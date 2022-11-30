#include <bits/stdc++.h>

#include <unordered_set>

using namespace std;

queue<pair<int, int> > Queue;
unordered_set<int> Set;
int Answer;

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
	Queue.push(make_pair(N, 0));
}

void bfs(void)
{
	while (!Queue.empty())
	{
		int a = Queue.front().first;
		int level = Queue.front().second;
		Queue.pop();
		Set.insert(a);
		if (a == M)
		{
			Answer = level;
			break;
		}
		if (a + 1 <= 100000 && Set.find(a + 1) == Set.end())
			Queue.push(make_pair(a + 1, level + 1));
		if (a - 1 >= 0 && Set.find(a - 1) == Set.end())
			Queue.push(make_pair(a - 1, level + 1));
		if (2 * a <= 100000 && Set.find(2 * a) == Set.end())
			Queue.push(make_pair(2 * a, level + 1));
	}
}

void solve(void)
{
	bfs();
}

void output(void)
{
	cout << Answer << "\n";
}

int main(void)
{
	Prologue();
	input();
	solve();
	output();
}