#include<bits/stdc++.h>
#include<iostream>
using namespace std;

#define ll long long int  

/*
DFS -> 
Depth First Search
TC and SC: O(V+E)
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
1 7 6 3 5 4 8 2 

*/

void dfs(int child,vector<vector<int>>&graph,vector<bool>&visited){
	visited[child] = true;
	cout<<child<<" ";
	for(int i =0;i<graph[child].size();i++){
		if(!visited[graph[child][i]]){
			dfs(graph[child][i],graph,visited);
		}
	}
}

int main(){
	int n;
	cin>>n;
	int m;
	cin>>m;
	vector<vector<int>>graph(n+1);
	for(int i =0;i<m;i++){
		int a,b;
		cin>>a>>b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	vector<bool>visited(n+1,false);
	dfs(1,graph,visited);
}
