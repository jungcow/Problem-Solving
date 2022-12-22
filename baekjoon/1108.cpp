#include <bits/stdc++.h>

#include <unordered_map>
#include <unordered_set>
#include <functional>

using namespace std;

unordered_map<string, vector<string> > graph;
unordered_map<string, vector<string> > revGraph;

unordered_set<string> graph_name;

stack<string> Stack;
unordered_map<string, bool> Marking;
unordered_map<string, bool> RevMarking;
unordered_map<long long, vector<string> > SCC;
unordered_map<string, unsigned long long> scoreBoard;

string SearchFor;
long long N;

void Prologue(void)
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
}

void input(void)
{
	cin >> N;
	for (long long i = 0; i < N; i++)
	{
		string to;
		long long num;
		cin >> to >> num;
		graph_name.insert(to);
		scoreBoard[to] = 1;
		for (long long j = 0; j < num; j++)
		{
			string from;
			cin >> from;
			graph[from].push_back(to);
			revGraph[to].push_back(from);
			graph_name.insert(from);
			scoreBoard[from] = 1;
		}
	}
	cin >> SearchFor;
}

void dfs(string currNode)
{
	Marking[currNode] = true;
	vector<string> adjs = graph[currNode];
	size_t size = adjs.size();
	for (long long i = 0; i < size; i++)
	{
		if (!Marking[adjs[i]])
		{
			dfs(adjs[i]);
		}
	}
	Stack.push(currNode);
}

void revDfs(string currNode, long long currDfsTree)
{
	RevMarking[currNode] = true;
	vector<string> adjs = revGraph[currNode];
	size_t size = adjs.size();
	for (long long i = 0; i < size; i++)
	{
		if (!RevMarking[adjs[i]])
		{
			revDfs(adjs[i], currDfsTree);
		}
	}
	SCC[currDfsTree].push_back(currNode);
}

void addScore(const vector<string>& currSet)
{
	size_t currSetSize = currSet.size();
	for (long long j = 0; j < currSetSize; j++)
	{
		vector<string> adjs = graph[currSet[j]];
		size_t adjsSize = adjs.size();
		for (long long k = 0; k < adjsSize; k++)
		{
			if (find(currSet.begin(), currSet.end(), adjs[k]) == currSet.end())
			{
				scoreBoard[adjs[k]] += scoreBoard[currSet[j]];
			}
		}
	}
}

void calculateScore(void)
{
	size_t size = SCC.size();
	for (long long i = 0; i < size; i++)
	{
		vector<string> currSet = SCC[i];
		addScore(currSet);
	}
}

void solve(void)
{
	size_t size = graph_name.size();
	unordered_set<string>::iterator it = graph_name.begin();
	unordered_set<string>::iterator end = graph_name.end();
	for (; it != end; it++)
	{
		if (!Marking[*it])
			dfs(*it);
	}
	long long dfsTree = 0;
	while (!Stack.empty())
	{
		string currNode = Stack.top();
		Stack.pop();
		if (!RevMarking[currNode])
		{
			revDfs(currNode, dfsTree);
		}
		dfsTree++;
	}
	calculateScore();
}

void output(void)
{
	cout << scoreBoard[SearchFor] << "\n";
}

int main(void)
{
	Prologue();
	input();
	solve();
	output();
}
