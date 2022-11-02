#include "bits/stdc++.h"

using namespace std;

int dp[1001];

int main(void)
{
	int N;
	cin >> N;
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= N; i++)
	{
		// dp[i] = 2 * dp[i - 2] + (dp[i - 1] - dp[i - 2]);
		dp[i] = (dp[i - 1] % 10007 + dp[i - 2] % 10007) % 10007;
	}
	printf("%d\n", dp[N] % 10007);
}