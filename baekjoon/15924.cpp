#include <bits/stdc++.h>

using namespace std;
#define MAX 3001

int N, M;

char arr[MAX][MAX];
unsigned long long Answer[MAX][MAX];

void Prologue(void)
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
}

void input(void)
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
			Answer[i][j] = 1;
		}
	}
}

void event(int i, int j, char eventChar)
{
	switch (eventChar)
	{
	case 'S':
		Answer[i + 1][j] = (Answer[i + 1][j] + Answer[i][j]) % 1000000009;
		break;
	case 'E':
		Answer[i][j + 1] = (Answer[i][j + 1] + Answer[i][j]) % 1000000009;
		break;
	case 'B':
		Answer[i + 1][j] = (Answer[i + 1][j] + Answer[i][j]) % 1000000009;
		Answer[i][j + 1] = (Answer[i][j + 1] + Answer[i][j]) % 1000000009;
		break;
	case 'X':
		return;
	}
}

void solve(void)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			event(i, j, arr[i][j]);
		}
	}
}

void output(void)
{
	cout << Answer[N - 1][M - 1] % 1000000009 << "\n";
}

int main(void)
{
	Prologue();
	input();
	solve();
	output();
}
