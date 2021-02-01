#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
	vector<int> *adj;
	int size;
	Graph(int n)
	{
		adj = new vector<int>[n];
		size = n;
	}
	void addEdge(int from, int to)
	{
		adj[from].push_back(to);
	}
};
void dfs_util(vector<int> adj[], int i, bool visited[])
{
	visited[i] = true;
	cout << i << " ";
	for (auto it = adj[i].begin(); it != adj[i].end(); ++it)
	{
		if (!visited[*it])
		{
			dfs_util(adj, *it, visited);
		}
	}
}
void dfs(vector<int> adj[], int n, int start)
{
	bool visited[n];
	for (int i = 0; i < n; ++i)
	{
		visited[i] = false;
	}
	for (int i = 0; i < n; ++i)
	{
		if (!visited[i])
		{
			dfs_util(adj, i, visited);
		}
	}
}
//Breadth First Search
void bfs(vector<int> adj[], int n, int start, bool visited[])
{
	std::queue<int> q;
	q.push(start); //start node

	while (!q.empty())
	{
		int el = q.front();
		cout << el << " ";
		visited[el] = true;
		q.pop();
		for (auto it = adj[el].begin(); it != adj[el].end(); ++it)
		{
			if (visited[*it] == false)
			{
				q.push(*it);
			}
		}
	}
}

int main()
{
	Graph g(4);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(2, 1);
	g.addEdge(3, 1);
	bool visited[g.size];
	for (int i = 0; i < g.size; ++i)
	{
		visited[i] = false;
	}
	for (int i = 0; i < g.size; ++i)
	{
		if (!visited[i])
		{
			bfs(g.adj, g.size, i, visited);
		}
	}
	cout << endl;
	dfs(g.adj, g.size, 0);
	cout << endl;
	return 0;
}