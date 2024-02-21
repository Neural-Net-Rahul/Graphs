#include<bits/stdc++.h>
#include<iostream>
using namespace std;

#define ll long long int  

/*
BFS -> 
Breadth First Search
BFS has three alphbets 'B','F','S', so we will make three things
while implementing BFS-> adj. list, visited, queue
TC : O(V+2*E)
SC : O(V)
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
1 7 2 3 6 8 5 4 

*/

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
	queue<int>q;
	q.push(1);
	visited[1] = true;
	while(!q.empty()){
		int a = q.front();
		q.pop();
		cout<<a<<" ";
		for(int i =0;i<graph[a].size();i++){
			int child = graph[a][i];
			if(!visited[child]){
				q.push(child);
				visited[child] = true;
			}
		}
	}
	
}
