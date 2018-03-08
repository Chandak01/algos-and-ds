#include<iostream>
#include<stack>
#include<vector>
using namespace std;



void dfs( vector<vector< int > > graph, int src,vector<int> visited,stack<int> st)
{
	
	int n = graph.size();
	
	st.push(src);
	while(!st.empty())
	{
		int node = st.top();
		visited[node] = 1;
		st.pop();
		cout<<node<<" ";
		for(int i=0;i<graph[node].size();i++)
		{
			if(visited[graph[node][i]]==0)
			{
				visited[graph[node][i]]==1;
				dfs(graph,graph[node][i],visited,st);
			}
		}
	}
	return;
}

int main()
{
	int n;
	cin>>n;
	vector<vector<int> > graph(n);
	int m;
	cin>>m;
	while(m--)
	{
		int a,b;
		cin>>a>>b;
		graph[a].push_back(b);
	}
	int src;
	cin>>src;
	vector<int> visited(n,0);
	stack<int> st;
	dfs(graph,src,visited,st);
}