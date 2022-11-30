#include <bits/stdc++.h>

using namespace std;

#define MAX 100002

vector<int> graph[MAX];
bool Fans[MAX];
bool Marked[MAX];
int N, M;
int F;
bool Answer;

void Prologue(void)
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
}

void input(void)
{
	cin >> N >> M;
	for (int i = 1; i <= M; i++)
	{
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
	}
	cin >> F;
	for (int i = 1; i <= F; i++)
	{
		int a;
		cin >> a;
		Fans[a] = true;
	}
	Answer = false;
}

void dfs(int curr)
{
	Marked[curr] = true;
	if (Fans[curr])
		return;
	vector<int> currAdj = graph[curr];
	size_t size = currAdj.size();
	if (size == 0)
	{
		Answer = true;
		return;
	}
	for (size_t i = 0; i < size; i++)
		if (!Marked[currAdj[i]])
			dfs(currAdj[i]);
}

void solve(void)
{
	dfs(1);
}

void output(void)
{
	if (Answer)
		cout << "yes\n";  // don't meet
	else
		cout << "Yes\n";
}

int main(void)
{
	Prologue();
	input();
	solve();
	output();
}