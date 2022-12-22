#include <bits/stdc++.h>

using namespace std;
#define MAX 100001
#define NODE_MAX 10001

vector<int> graph[MAX];
vector<int> reverseGraph[MAX];

int Marking[NODE_MAX];
int MarkingForRev[NODE_MAX];
vector<vector<int> > SCC;
stack<int> Stack;

int N, M;

void Prologue(void)
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
}

void input(void)
{
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		reverseGraph[b].push_back(a);
	}
}

void dfsForPostNumbering(int curr)
{
	Marking[curr] = 1;
	vector<int> adjs = graph[curr];
	size_t size = adjs.size();
	for (int i = 0; i < size; i++)
		if (!Marking[adjs[i]])
			dfsForPostNumbering(adjs[i]);
	Stack.push(curr);
}

void reverseDfsForDetachingSCC(int curr, int dfsTreeNum)
{
	MarkingForRev[curr] = 1;
	vector<int> adjs = reverseGraph[curr];
	size_t size = adjs.size();
	for (int i = 0; i < size; i++)
		if (!MarkingForRev[adjs[i]])
			reverseDfsForDetachingSCC(adjs[i], dfsTreeNum);
	SCC[dfsTreeNum].push_back(curr);
}

void solve(void)
{
	for (int i = 1; i <= N; i++)
		if (!Marking[i])
			dfsForPostNumbering(i);
	int dfsTreeNum = 0;
	while (!Stack.empty())
	{
		int currNode = Stack.top();
		Stack.pop();
		if (!MarkingForRev[currNode])
		{
			SCC.push_back(vector<int>());
			reverseDfsForDetachingSCC(currNode, dfsTreeNum);
			dfsTreeNum++;
		}
	}
}

void output(void)
{
	size_t SCCSize = SCC.size();
	for (int i = 0; i < SCCSize; i++)
	{
		sort(SCC[i].begin(), SCC[i].end());
	}
	sort(SCC.begin(), SCC.end());
	cout << SCC.size() << "\n";
	for (int i = 0; i < SCCSize; i++)
	{
		size_t treeSize = SCC[i].size();
		for (int j = 0; j < treeSize; j++)
		{
			cout << SCC[i][j] << " ";
		}
		cout << "-1\n";
	}
}

int main(void)
{
	Prologue();
	input();
	solve();
	output();
}