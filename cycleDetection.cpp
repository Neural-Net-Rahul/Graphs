#include<bits/stdc++.h>
#include<iostream>
using namespace std;

#define ll long long int  

/*
Cycle Detection

Undirected
DFS -> if child!=parent and child is visited, it means a cycle
BFS -> same as DFS

Directed
DFS -> 2 visited
BFS -> Kahn's algorithm
(Will discuss about it in Topological Sorting)
*/

/* 
Input ->
8 10
1 7
1 2
1 3
3 6
7 6
7 8
8 6
6 5
5 3
3 4

Output ->
U D : Cycle
U B : Cycle
D B : Cycle


*/

void dfs(int child,int parent,vector<vector<int>>&graphs,vector<bool>&visited,bool&ans){
	visited[child] = true;
	for(int i =0;i<graphs[child].size();i++){
		if(!visited[graphs[child][i]]){
			dfs(graphs[child][i],child,graphs,visited,ans);
		}
		else{
			if(graphs[child][i]!=parent){
				ans = true;
			}
		}
	}
}

void dfsDirected(int child,vector<bool>&visited1,vector<bool>&visited2,vector<vector<int>>&graph,bool&ans){
	visited1[child] = true;
	visited2[child] = true;
	for(int i =0;i<graph[child].size();i++){
		if(!visited1[graph[child][i]]){
			dfsDirected(graph[child][i],visited1,visited2,graph,ans);
		}
		if(visited2[graph[child][i]]){
			ans = true;
		}
	}
	visited2[child] = false;
}

int main(){
	int n;
	cin>>n;
	int m;
	cin>>m;
	vector<vector<int>>graph(n+1);
	vector<vector<int>>d_graph(n+1);
	for(int i =0;i<m;i++){
		int a,b;
		cin>>a>>b;
		graph[a].push_back(b);
		graph[b].push_back(a);
		d_graph[a].push_back(b);
	}



	// undirected -> dfs

	vector<bool>uVisited(n+1,false);
	bool ans = false;
	dfs(1,-1,graph,uVisited,ans);
	if(ans){
		cout<<"U D : Cycle"<<endl;
	}
	else{
		cout<<"U D : Not Cycle"<<endl;
	}




	// undirected -> bfs

	queue<pair<int,int>>q;
	q.push({1,-1});
	bool isCycle = false;
	vector<bool>uBVisited(n+1,false);
	uBVisited[1] = true;
	while(!q.empty()){
		pair<int,int>p = q.front();
		q.pop();
		int child = p.first;
		int parent = p.second;
		for(int i =0;i<graph[child].size();i++){
			int child_child = graph[child][i];
			if(!uBVisited[child_child]){
				q.push({child_child,child});
				uBVisited[child_child] = true;
			}
			else{
				if(child_child!=parent){
					isCycle = true;
					break;
				}
			}
		}
		if(isCycle){
			break;
		}
	}
	if(isCycle){
		cout<<"U B : Cycle"<<endl;
	}
	else{
		cout<<"U B : Not Cycle"<<endl;
	}




	// directed dfs -> 2 visited
	
	vector<bool>visited1(n+1,false);
	vector<bool>visited2(n+1,false);
	bool answer = false;
	dfsDirected(1,visited1,visited2,graph,answer);
	if(answer==false){
		cout<<"D B : Not Cycle"<<endl;
	}
	else{
		cout<<"D B : Cycle"<<endl;
	}

	// directed bfs -> done in Topological Sort

}
