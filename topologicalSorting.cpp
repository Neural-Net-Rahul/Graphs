#include<bits/stdc++.h>
#include<iostream>
using namespace std;

#define ll long long int  

/*
Topological Sorting => applied on DAG (Directed acyclic graph)
=> DFS or,
=> Kahn's Algorithm
=> Used in cycle detection also -> if at the end whole indegree array does not becomes 0,
it means there is cycle
*/

/* 
Input ->
6 9
1 2
1 3
2 3
2 4
4 3
4 5
3 5
5 6
4 6

Output ->
1 2 4 3 5 6 
1 2 4 3 5 6 

*/

void dfs(int child,vector<vector<int>>&graph,stack<int>&s,vector<bool>&visited){
	visited[child] = true;
	for(int  i =0;i<graph[child].size();i++){
		if(!visited[graph[child][i]]){
			dfs(graph[child][i],graph,s,visited);
		}
	}
	s.push(child);
}

int main(){
	int n;
	cin>>n;
	int m;
	cin>>m;
	vector<vector<int>>graph(n+1);
	vector<int>indegree(n+1);
	for(int i =0;i<m;i++){
		int a,b;
		cin>>a>>b;
		indegree[b]++;
		graph[a].push_back(b);
	}

	// Kahn's algorithm
	/*
	When we heard of Kahn's algo, the first thing that came to my mind is indegree array and
	second thing is, those having indegree 0, put them in queue. Do we ever think of visited 
	array -> NO, so we will not think of about it.
	When we think of queue, the first think came to our mind is !empty, .front .pop go to
	child
	*/
	queue<int>q;
	for(int i =1;i<=n;i++){
		if(indegree[i]==0){
			q.push(i);
		}
	}
	vector<int>ans;
	while(!q.empty()){
		int a = q.front();
		ans.push_back(a);
		q.pop();
		for(int i =0;i<graph[a].size();i++){
			int child = graph[a][i];
			indegree[child]--;
			if(indegree[child]==0){
				q.push(child);
			}
		}
	}
	for(int i =0;i<ans.size();i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;



	// using DFS
	// if a node has its dfs complete, then put it into stack, top to bottom is answer.
	// meaning of dfs complete -> when all it's child are visited.
	stack<int>s;
	vector<bool>visited(n+1,false);
	dfs(1,graph,s,visited);
	while(!s.empty()){
		cout<<s.top()<<" ";
		s.pop();
	}
}
