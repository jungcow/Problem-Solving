#include "bits/stdc++.h"

using namespace std;

vector<int> graph[32001];

int N, M;

int PostDfn[32001];
int postdfn;
int Visited[32001];

vector<int> postorder;

void printGraph()
{
	for (int i = 1; i <= N; i++)
	{
		printf("%d: ", i);
		for (int j = 0; j < graph[i].size(); j++)
		{
			printf("%d", graph[i][j]);
		}
		printf("\n");
	}
}

void printArray(int* arr)
{
	for (int i = 1; i <= N; i++)
	{
		printf("|%3d|", i);
	}
	printf("\n");
	for (int i = 1; i <= N; i++)
	{
		printf("|%3d|", arr[i]);
	}
	printf("\n");
}

void input()
{
	postdfn = 0;
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
	}
#if DEBUG
	printGraph();
#endif
}

void dfs(int num)
{
	vector<int> Adjacency = graph[num];
	int size = Adjacency.size();
	Visited[num] = 1;
	for (int i = 0; i < size; i++)
	{
		if (!Visited[Adjacency[i]])
		{
			dfs(Adjacency[i]);
		}
	}
	postorder.push_back(num);
#if DEBUG
	PostDfn[num] = ++postdfn;
#endif
}

void solve()
{
	dfs(1);
	for (int i = 1; i <= N; i++)
	{
		if (!Visited[i])
		{
			dfs(i);
		}
	}
#if DEBUG
	printArray(Visited);
	printArray(PostDfn);
#endif
}

void output()
{
	int size = postorder.size();
	for (int i = size - 1; i >= 0; i--)
	{
		printf("%d ", postorder[i]);
	}
	printf("\n");
}

int main(void)
{
	input();
	solve();
	output();
}