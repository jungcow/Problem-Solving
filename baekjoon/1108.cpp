#include <bits/stdc++.h>

#include <unordered_map>

using namespace std;

int N;

string SearchFor;
unordered_map<string, unordered_map<string, int> > graph;  // pair<string, DFS Tree 번호>
unordered_map<string, vector<pair<string, int> > > reverseGraph;
vector<pair<string, int> > PostDfnVec;
unordered_map<string, int> RevDfsTree;
vector<vector<string> > RevDfsTree2;
unordered_map<string, vector<string> > CrossEdgs;

int Dfn;
unordered_map<string, bool> Mark;
unordered_map<string, unsigned long long> Scores;

void Prologue(void)
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
}

void printMapStringInt(unordered_map<string, int> map)
{
	unordered_map<string, int>::iterator it = map.begin();
	unordered_map<string, int>::iterator end = map.end();
	for (; it != end; it++)
	{
		cout << it->first << "(";
		cout << it->second << ")";
	}
	cout << "\n";
}

void printGraph(void)
{
	cout << "Search Website Name: " << SearchFor << "\n";
	unordered_map<string, unordered_map<string, int> >::iterator it = graph.begin();
	unordered_map<string, unordered_map<string, int> >::iterator end = graph.end();
	for (; it != end; it++)
	{
		cout << it->first << ": ";
		printMapStringInt(it->second);
	}
}

void printPostOrder(void)
{
	int size = PostDfnVec.size();
	for (int i = 0; i < size; i++)
	{
		string str = PostDfnVec[i].first;
		int postorder = PostDfnVec[i].second;
		cout << "str: " << str << " post_num: " << postorder << "\n";
	}
}

void printMarked(void)
{
	unordered_map<string, bool>::iterator it = Mark.begin();
	unordered_map<string, bool>::iterator end = Mark.end();

	for (; it != end; it++)
	{
		cout << it->first << ": " << it->second << "\n";
	}
}

void printDfsTreeGroup(void)
{
	int treeNum = RevDfsTree2.size();
	for (int i = 0; i < treeNum; i++)
	{
		int nodeNum = RevDfsTree2[i].size();
		cout << "[" << i << "]: { ";
		for (int j = 0; j < nodeNum; j++)
		{
			cout << RevDfsTree2[i][j] << ", ";
		}
		cout << " }\n";
	}
}

void input(void)
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string to;
		int linkNum;
		cin >> to >> linkNum;
		Mark[to] = false;
		Scores[to] = 1;
		for (int j = 0; j < linkNum; j++)
		{
			string from;
			cin >> from;
			graph[from][to] = 0;
			Mark[from] = false;
			reverseGraph[to].push_back(make_pair(from, 0));
			Scores[from] = 1;
		}
	}
	cin >> SearchFor;
	Scores[SearchFor] = 1;
#if DEBUG
	printGraph();
#endif
}

void initMark()
{
	unordered_map<string, bool>::iterator it = Mark.begin();
	unordered_map<string, bool>::iterator end = Mark.end();

	it = Mark.begin();
	end = Mark.end();
	for (; it != end; it++)
		it->second = false;
}

void dfs(const string& currStr)
{
	// Do Create PostDfnVec!
	unordered_map<string, int> adjacency = graph[currStr];
	int size = adjacency.size();
	Mark[currStr] = true;

	unordered_map<string, int>::iterator it = adjacency.begin();
	unordered_map<string, int>::iterator end = adjacency.end();
	for (; it != end; it++)
	{
		string nextStr = it->first;
		if (!Mark[nextStr])
			dfs(nextStr);
	}
	PostDfnVec.push_back(make_pair(currStr, ++Dfn));
}

void postNumbering(void)
{
	unordered_map<string, bool>::iterator it = Mark.begin();
	unordered_map<string, bool>::iterator end = Mark.end();

	for (; it != end; it++)
		if (!it->second)  // 첫번째로 발견한 unmarked node로 다시 DFS를 돌림
			dfs(it->first);
#if DEBUG
	printPostOrder();
#endif
	initMark();
}

void reverseDfs(string currStr, int dfsTreeNum, int* nodeNum)
{
	// Do DFS Tree Numbering!
	vector<pair<string, int> > adjacency = reverseGraph[currStr];
	int size = adjacency.size();
	Mark[currStr] = true;
	RevDfsTree[currStr] = dfsTreeNum;
	RevDfsTree2[dfsTreeNum].push_back(currStr);
	*nodeNum = *nodeNum + 1;

	for (int i = 0; i < size; i++)
	{
		string nextStr = adjacency[i].first;
		if (!Mark[nextStr])
		{
			reverseDfs(nextStr, dfsTreeNum, nodeNum);
		}
		else if (Mark[nextStr] && RevDfsTree[nextStr] != dfsTreeNum)  // 지금 돌아가고 있는 중이라
		{
			CrossEdgs[nextStr].push_back(currStr);
#if DEBUG
			cout << "Cross Edge -> [ " << nextStr << "(" << RevDfsTree[nextStr] << ") : " << currStr << "(" << dfsTreeNum << ") ]\n";
#endif
		}
	}
}

void calculateScore(void)
{
	unordered_map<string, vector<string> >::iterator it = CrossEdgs.begin();
	unordered_map<string, vector<string> >::iterator end = CrossEdgs.end();

	int size = RevDfsTree2.size();
	for (int i = 0; i < size; i++)
	{
		vector<string> currTree = RevDfsTree2[i];
		int treeSize = currTree.size();
		for (int j = 0; j < treeSize; j++)
		{
			if (CrossEdgs.find(currTree[j]) != CrossEdgs.end())
			{
				vector<string> nodes = CrossEdgs[currTree[j]];
				int nodeSize = nodes.size();
				for (int k = 0; k < nodeSize; k++)
				{
#if DEBUG
					cout << CrossEdgs[currTree[j]][k] << " += " << currTree[j] << " => ";
#endif
					Scores[CrossEdgs[currTree[j]][k]] += Scores[currTree[j]];
#if DEBUG
					cout << Scores[CrossEdgs[currTree[j]][k]] << "\n";
#endif
				}
			}
		}
	}
}

void solve(void)
{
	postNumbering();
	int size = PostDfnVec.size();
	int dfsTreeNum = 0;
	for (int i = size - 1; i >= 0; i--)
	{
		int nodeNum = 0;
		RevDfsTree2.push_back(vector<string>());
		reverseDfs(PostDfnVec[i].first, dfsTreeNum++, &nodeNum);
		i -= (nodeNum - 1);
	}
	initMark();
#if DEBUG
	printMapStringInt(RevDfsTree);
	printDfsTreeGroup();
#endif
	calculateScore();
}

void output(void)
{
	cout << Scores[SearchFor] << "\n";
}

int main(void)
{
	Prologue();
	input();
	solve();
	output();
}
