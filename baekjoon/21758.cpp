#include <bits/stdc++.h>

using namespace std;

#define MAX 100002

int N;
int MaxSum;
int PreSum[MAX];
int Input[MAX];

void Prologue(void)
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
}

void input(void)
{
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> Input[i];
		PreSum[i] = PreSum[i - 1] + Input[i];
	}
}

void solve(void)
{
	// 1. bee1 = 1, bee2 = ?, beeBox = N
	// 2. bee1 = N, bee2 = ?, beeBox = 1
	// 3. bee1 = 1, bee2 = N, beeBox = ?
	unsigned int bee1PreSum = PreSum[N] - PreSum[1];
	for (int i = 2; i <= N - 1; i++)
	{
		int result = bee1PreSum - Input[i] + PreSum[N] - PreSum[i];
		if (MaxSum < result)
		{
#if DEBUG
			cout << "[first case] bee2 index is " << i << "\n";
#endif
			MaxSum = result;
		}
	}

	bee1PreSum = PreSum[N - 1];
	for (int i = N - 1; i >= 2; i--)
	{
		int result = bee1PreSum - Input[i] + PreSum[i - 1];
		if (MaxSum < result)
		{
#if DEBUG
			cout << "[second case] bee2 index is " << i << "\n";
#endif
			MaxSum = result;
		}
	}

	for (int i = 2; i <= N - 1; i++)
	{
		int result = PreSum[i] - PreSum[1] + PreSum[N] - PreSum[i - 1] - Input[N];
		if (MaxSum < result)
		{
#if DEBUG
			cout << "[third case] beeBox index is " << i << "\n";
#endif
			MaxSum = result;
		}
	}
	cout << MaxSum << "\n";
}

int main(void)
{
	Prologue();
	input();
	solve();
}