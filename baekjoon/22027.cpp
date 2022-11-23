#include <bits/stdc++.h>

// start time: Sat Nov 19 15:13:43 KST 2022
// end time :

using namespace std;

#define PARENT 1
#define CHILD 2
#define BACKFORWARD 3

vector<int> graph[10000];
vector<int> Type[10000];
stack<int> stck;

int dfsnum;
int DfsNum[10000];

int N, M;

void printGraph()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			printf("%3d", graph[i][j]);
		}
		printf("\n");
	}
}

void input()
{
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
#ifdef DEBUG
	printGraph();
#endif
}

void dfsForTypeOfEdge(int p)
{
	while (!stck.empty())
	{
		int n = stck.top();
		DfsNum[n] = dfsnum++;
		for (int i = 0; i < n; i++)
		{
			if (graph[n][i] == p)
			{
				Type[n][i] = PARENT;
			}
			else if (DfsNum[graph[n][i]] == 0)
			{
				Type[n][i] = CHILD;
				stck.push(graph[n][i]);
				dfsForTypeOfEdge(n);
			}
			else
			{
				Type[n][i] = BACKFORWARD;
			}
		}
	}
#ifdef DEBUG
	printGraph();
#endif
}

void solve()
{
	stck.push(1);
	dfsForTypeOfEdge(0);
	dfsFor
}

int main(void)
{
	input();
	solve();
}