#include "bits/stdc++.h"

using namespace std;

int dp[1000001];

int min(int i, int j, int k)
{
	int m = i;
	if (m > j)
		m = j;
	if (m > k)
		m = k;
	return m;
}

int main(void)
{
	int N;
	cin >> N;

	dp[0] = 0;
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;
	int a, b, c;
	for (int i = 4; i <= N; i++)
	{
		a = b = c = INT_MAX;
		if (i % 3 == 0)
			a = dp[i / 3];
		if (i % 2 == 0)
			b = dp[i / 2];
		c = dp[i - 1];
		dp[i] = min(a, b, c) + 1;
	}
	printf("%d\n",dp[N]);
}