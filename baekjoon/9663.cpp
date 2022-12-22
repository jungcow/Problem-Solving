#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> Map;
int Answer;

void Prologue(void)
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
}

void input(void)
{
	cin >> N;
	Map.assign(N * N, 0);
}

const vector<int> get_possible_idx2(const vector<int>& board, int level)
{
	vector<int> possible;
	for (int i = 0; i < N; i++)
	{
		if (!board[N * level + i])
			possible.push_back(i);
	}
	return possible;
}

void solve_backtracking2(const vector<int>& board, int level)
{
	const vector<int>& possible = get_possible_idx2(board, level);
	int size = possible.size();
	if (level == N - 1)
	{
		Answer += size;
		return;
	}
	for (int i = 0; i < size; i++)
	{
		vector<int> tmp = board;
		tmp[N * level + possible[i]] = 1;
		int dx = 1;
		for (int l = level + 1; l < N; l++, dx++)
		{
			tmp[N * l + possible[i]] = -1;
			if (possible[i] - dx >= 0)
				tmp[N * l + (possible[i] - dx)] = -1;
			if (possible[i] + dx < N)
				tmp[N * l + (possible[i] + dx)] = -1;
		}
		solve_backtracking2(tmp, level + 1);
	}
}

void solve(void)
{
	solve_backtracking2(Map, 0);
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