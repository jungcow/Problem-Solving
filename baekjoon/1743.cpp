#include <bits/stdc++.h>

using namespace std;

#define MAX 100

int N, M, K;
int Map[MAX + 2][MAX + 2];
int Mark[MAX + 2][MAX + 2];

int Max;

int di[] = {-1, 1, 0, 0};
int dj[] = {0, 0, -1, 1};

void printMap(int (*matrix)[MAX + 2][MAX + 2])
{
	for (int i = 0; i < N + 2; i++)
	{
		for (int j = 0; j < M + 2; j++)
		{
			cout << std::setw(3) << std::right << (*matrix)[i][j];
		}
		cout << "\n";
	}
	cout << "\n";
}

void input(void)
{
	cin >> N >> M >> K;
	for (int i = 0; i < M + 2; i++)
	{
		Map[0][i] = -1;
		Map[N + 1][i] = -1;
	}
	for (int i = 0; i < N + 2; i++)
	{
		Map[i][0] = -1;
		Map[i][M + 1] = -1;
	}
	for (int i = 0; i < N + 2; i++)
	{
		for (int j = 0; j < M + 2; j++)
		{
			Mark[i][j] = -1;
		}
	}
	for (int i = 0; i < K; i++)
	{
		int a, b;
		cin >> a >> b;
		Map[a][b] = 1;
		Mark[a][b] = 0;
	}
#if DEBUG
	printMap(&Map);
	printMap(&Mark);
#endif
}

void dfs(pair<int, int> curr)
{
	int currI = curr.first;
	int currJ = curr.second;

	Mark[currI][currJ] = 1;

#if DEBUG
	printMap(&Mark);
#endif

	Max++;

	for (int i = 0; i < 4; i++)
	{
		int nextI = currI + di[i];
		int nextJ = currJ + dj[i];

		if (!Mark[nextI][nextJ] && Map[nextI][nextJ] == 1)
			dfs(make_pair(nextI, nextJ));
	}
}

void solve(void)
{
	// dfs
	int max = 0;
	for (int i = 1; i < N + 1; i++)
	{
		for (int j = 1; j < M + 1; j++)
		{
			if (!Mark[i][j])
			{
				dfs(make_pair(i, j));
				max = max < Max ? Max : max;
				Max = 0;
			}
		}
	}
	Max = max;
}

void output(void)
{
	cout << Max << endl;
}

int main(void)
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	solve();
	output();
}