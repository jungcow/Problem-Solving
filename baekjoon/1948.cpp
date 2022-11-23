#include "bits/stdc++.h"

using namespace std;

#define MaxNum 10001

vector<pair<int, int> > graph[MaxNum];
vector<pair<int, int> > reverseGraph[MaxNum];
set<pair<int, int> > trace;
// int trace[MaxNum];

vector<int> Postorder;
int PostDfn[MaxNum];
int postDfn;
int N, M;
int Start, End;
int Visited[MaxNum];
int Max[MaxNum];
// int traceMarking[MaxNum];

void printGraph()
{
	for (int i = 1; i <= N; i++)
	{
		printf("%d: ", i);
		for (int j = 0; j < graph[i].size(); j++)
		{
			printf("%d(%d) ", graph[i][j].first, graph[i][j].second);
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

void printArray(vector<int> vec)
{
	for (int i = 1; i <= N; i++)
	{
		printf("|%3d|", i);
	}
	printf("\n");
	for (int i = 1; i <= N; i++)
	{
		printf("|%3d|", vec[i]);
	}
	printf("\n");
}

void input()
{
	cin >> N >> M;
	postDfn = 0;
	for (int i = 0; i < M; i++)
	{
		int a, b, w;
		cin >> a >> b >> w;
		graph[a].push_back(make_pair(b, w));
		reverseGraph[b].push_back(make_pair(a, w));
	}
	cin >> Start >> End;
	Postorder.push_back(0);
#if DEBUG
	printGraph();
#endif
}

void dfs(int n)
{
	vector<pair<int, int> > Adjacencies = graph[n];
	int size = Adjacencies.size();

	Visited[n] = 1;
	for (int i = 0; i < size; i++)
	{
		if (!Visited[Adjacencies[i].first])
		{
			dfs(Adjacencies[i].first);
		}
	}
	Postorder.push_back(n);
#if DEBUG
	PostDfn[n] = ++postDfn;
#endif
}

void topological_sort(void)
{
	dfs(Start);
	reverse(Postorder.begin() + 1, Postorder.end());
#if DEBUG
	printArray(Postorder);
#endif
}

int find_longest_path()
{
	int s = Start;
	int size = N;
	for (int i = 0; i < size; i++)
	{
		int currNode = Postorder[i];
		vector<pair<int, int> > adjacencies = graph[currNode];
		int adjSize = adjacencies.size();
		for (int j = 0; j < adjSize; j++)
		{
			Max[adjacencies[j].first] = max(Max[adjacencies[j].first], Max[currNode] + adjacencies[j].second);
		}
	}
#if DEBUG
	printArray(Max);
#endif
	return Max[End];
}

int trace_edge()
{
	int edgeNum = 0;

	queue<int> box;
	box.push(End);
	while (!box.empty())
	{
		int currNode = box.front();
		box.pop();
		vector<pair<int, int> > adjacencies = reverseGraph[currNode];
		int adjSize = adjacencies.size();
		for (int j = 0; j < adjSize; j++)
		{
			int nextNode = reverseGraph[currNode][j].first;
			int nextWeight = reverseGraph[currNode][j].second;
			if (Max[currNode] - Max[nextNode] == nextWeight)
			{
				if (trace.find(make_pair(currNode, nextNode)) == trace.end())
				{
					edgeNum++;
					box.push(nextNode);
					trace.insert(make_pair(currNode, nextNode));
#if DEBUG
					printf("from: %d, to: %d\n", currNode, nextNode);
#endif
				}
			}
		}
	}
	return edgeNum;
}

void solve()
{
	topological_sort();
	int max = find_longest_path();
	int edgeNum = trace_edge();
#if DEBUG
	printf("max, edgeNum: ");
#endif
	printf("%d %d\n", max, edgeNum);
}

int main(void)
{
	input();
	solve();
}