#include "bits/stdc++.h"

using namespace std;

int dp[5001];

int min(int i, int j)
{
	int m = i;
	if (i > j)
		m = j;
	return m;
}
int max(int i, int j)
{
	int m = i;
	if (i < j)
		m = j;
	return m;
}

void solve(int n)
{
	dp[0] = dp[1] = dp[2] = -1;
	dp[3] = 1;
	dp[4] = -1;
	dp[5] = 1;
	for (int i = 6; i <= n; i++)
	{
		int m;
		if (dp[i - 3] < 0 || dp[i - 5] < 0)
			m = max(dp[i-3], dp[i-5]);
		else
			m = min(dp[i - 3], dp[i - 5]);
		if (m < 0)
			dp[i] = -1;
		else
			dp[i] = m + 1;
	}
}

int main(void)
{
	int N;
	cin >> N;
	solve(N);
	cout << dp[N] << endl;
}