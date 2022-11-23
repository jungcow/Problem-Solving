#include "bits/stdc++.h"

/**
 * 문제 : 토마토
 */
/**
 * 철수의 토마토 농장에서는 토마토를 보관하는 큰 창고를 가지고 있다. 토마토는 아래의 그림과 같이 격자 모양 상자의 칸에 하나씩 넣어서 창고에 보관한다.
 *
 *
 *
 * 창고에 보관되는 토마토들 중에는 잘 익은 것도 있지만, 아직 익지 않은 토마토들도 있을 수 있다. 보관 후 하루가 지나면, 익은 토마토들의 인접한 곳에 있는 익지 않은 토마토들은 익은 토마토의 영향을 받아 익게 된다. 하나의 토마토의 인접한 곳은 왼쪽, 오른쪽, 앞, 뒤 네 방향에 있는 토마토를 의미한다. 대각선 방향에 있는 토마토들에게는 영향을 주지 못하며, 토마토가 혼자 저절로 익는 경우는 없다고 가정한다. 철수는 창고에 보관된 토마토들이 며칠이 지나면 다 익게 되는지, 그 최소 일수를 알고 싶어 한다.
 *
 * 토마토를 창고에 보관하는 격자모양의 상자들의 크기와 익은 토마토들과 익지 않은 토마토들의 정보가 주어졌을 때, 며칠이 지나면 토마토들이 모두 익는지, 그 최소 일수를 구하는 프로그램을 작성하라. 단, 상자의 일부 칸에는 토마토가 들어있지 않을 수도 있다.
 **/

using namespace std;

queue<int> box;
int Map[1002][1002];

int M, N;

int Min;

void printMap()
{
	for (int i = 0; i <= N + 1; i++)
	{
		for (int j = 0; j <= M + 1; j++)
		{
			printf("%3d", Map[i][j]);
		}
		printf("\n");
	}
}

void input()
{
	cin >> M >> N;
	for (int i = 0; i <= N + 1; i++)
	{
		for (int j = 0; j <= M + 1; j++)
		{
			Map[i][j] = -1;
		}
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> Map[i][j];
			if (Map[i][j] == 1)
			{
				box.push(i);
				box.push(j);
			}
		}
	}
#ifdef DEBUG
	printMap();
#endif
}

void infect(int i, int j, int ti, int tj)
{
	if (Map[ti][tj] == 0)
	{
		Map[ti][tj] = Map[i][j] + 1;
		if (Map[ti][tj] - 1 > Min)
		{
			Min = Map[ti][tj] - 1;
		}
		box.push(ti);
		box.push(tj);
	}
}

void event(int i, int j)
{
	infect(i, j, i - 1, j);
	infect(i, j, i + 1, j);
	infect(i, j, i, j - 1);
	infect(i, j, i, j + 1);
}

void solve()
{
	while (!box.empty())
	{
		int i = box.front();
		box.pop();
		int j = box.front();
		box.pop();
		event(i, j);
	}
}

void output()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (Map[i][j] == 0)
				Min = -1;
		}
	}
#ifdef DEBUG
	printMap();
#endif
	printf("%d\n", Min);
}

int main(void)
{
	input();
	solve();
	output();
}