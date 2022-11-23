#include <bits/stdc++.h>

// start time: Sat Nov 19 15:13:43 KST 2022
// end time : Sat Nov 19 17:08:32 KST 2022

using namespace std;

#define PARENT 1
#define CHILD 2
#define BACKFORWARD 3

vector<int> graph[10000];
vector<int> Type[10000];

int dfsnum;
int DfsNum[10001];
int L[10001];
int Cut[10001];
int CNum;

int N, M;

void printGraph()
{
    printf("======== graph matrix =======\n");
	for (int i = 0; i < N; i++)
	{
		printf("%d : ", i);
		for (int j = 0; j < graph[i].size(); j++)
		{
			printf("%3d", graph[i][j]);
		}
		printf("\n");
	}
    printf("===========================\n\n");
}

void input()
{
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		Type[a].push_back(0);
		graph[b].push_back(a);
		Type[b].push_back(0);
	}
#ifdef DEBUG
	printGraph();
#endif
}

void dfsForTypeOfEdge(int n, int p)
{
	DfsNum[n] = ++dfsnum;
	int s = graph[n].size();
	for (int i = 0; i < s; i++)
	{
		if (graph[n][i] == p)
		{
			Type[n][i] = PARENT;
		}
		else if (DfsNum[graph[n][i]] == 0)
		{
			Type[n][i] = CHILD;
			dfsForTypeOfEdge(graph[n][i], n);
		}
		else
		{
			Type[n][i] = BACKFORWARD;
		}
	}
}

int dfsForCalculate(int n, int p)
{
	int rv;
	L[n] = DfsNum[n];
	int s = graph[n].size();
	for (int i = 0; i < s; i++)
	{
		if (Type[n][i] == PARENT)
		{
		}
		else if (Type[n][i] == CHILD)
		{
			rv = dfsForCalculate(graph[n][i], n);
			L[n] = min(L[n], rv);
		}
		else
		{
			L[n] = min(L[n], DfsNum[graph[n][i]]);
		}
	}
	if (p == 0)
	{
		int cc = 0;
		for (int i = 0; i < s; i++)
		{
			if (Type[n][i] == CHILD)
			{
				cc++;
			}
		}
		if (cc > 1)
		{
			Cut[n] = 1;
			CNum++;
		}
	}
	else
	{
		for (int i = 0; i < s; i++)
		{
			if (Type[n][i] == CHILD)
			{
				if (L[graph[n][i]] >= DfsNum[n])
				{
					Cut[n] = 1;
					CNum++;
					break;
				}
			}
		}
	}
	return L[n];
}

void solve()
{
	dfsForTypeOfEdge(1, 0);
	for (int i = 1; i <= N; i++)
	{
		if (DfsNum[i] == 0)
		{
			dfsForTypeOfEdge(i, 0);
		}
	}
	dfsForCalculate(1, 0);
	for (int i = 1; i <= N; i++)
	{
		if (L[i] == 0)
		{
			dfsForCalculate(i, 0);
		}
	}
}

void output()
{
#ifdef DEBUG
	printf("cut vertex num: ");
#endif
	printf("%d\n", CNum);
#ifdef DEBUG
	printf("cut vertices: ");
#endif
	for (int i = 1; i <= N; i++)
	{
		if (Cut[i] == 1)
		{
			printf("%d ", i);
		}
	}
	printf("\n");
}

int main(void)
{
	input();
	solve();
	output();
}