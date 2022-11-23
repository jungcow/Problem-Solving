#include "bits/stdc++.h"

using namespace std;

vector<int> graph[100001];
std::stack<int> stck;
int Mark[100001];

int n;

void input()
{
	cin >> n;
	for (int i = 0; i + 1 < n; i++)
	{
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
}

void traversal()
{
	if (stck.empty())
	{
		return;
	}
	int top = stck.top();
	stck.pop();
	for (int i = 0; i < graph[top].size(); i++)
	{
		if (!Mark[graph[top][i]])
		{
			Mark[graph[top][i]] = top;
			stck.push(graph[top][i]);
			traversal();
		}
	}
}

void output()
{
	for (int i = 2; i <= n; i++)
	{
		if (Mark[i])
		{
			printf("%d\n", Mark[i]);
		}
	}
}

int main(void)
{
	input();
	stck.push(1);
	traversal();
	output();
}