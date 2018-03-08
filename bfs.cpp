#include<iostream>
#include<queue>
using namespace std;

void bfs(vector< vector<int> > graph,int src)
{
	int n = graph.size();
	vector<int> visited(n,0);
	queue<int> q;
	q.push(src);
	while(!q.empty())
	{
		int node = q.front();
		q.pop();
		cout<<node<<" ";
		visited[node] = 1;
		for(int i=0;i<graph[node].size();i++)
		{
			if(visited[graph[node][i]]==0)
				q.push(graph[node][i]);
			visited[graph[node][i]]==1;
		}
	}
	return;
}

int main()
{
	int n;
	cin>>n;
	vector< vector<int> > graph(n);
	int m;
	cin>>m;
	for(int i=0;i<m;i++)
	{
		int a,b;
		cin>>a>>b;
		graph[a].push_back(b);
		//graph[b].push_back(a);
	}
	int src;
	cin>>src;
	bfs(graph,src);
}