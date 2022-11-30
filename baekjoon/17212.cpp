#include <bits/stdc++.h>

using namespace std;

#define MAX 100001

int N;
int dp[MAX];

void Prologue(void)
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
}

void input(void)
{
	cin >> N;
}

int getMin(int a, int b, int c, int d)
{
	int min = a;
	if (min > b)
		min = b;
	if (min > c)
		min = c;
	if (min > d)
		min = d;
	return min;
}

void solve()
{
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 2;
	dp[4] = 2;
	dp[5] = 1;
	dp[6] = 2;
	dp[7] = 1;
	for (int i = 8; i <= N; i++)
		dp[i] = getMin(dp[i - 1], dp[i - 2], dp[i - 5], dp[i - 7]) + 1;
}

void output(void)
{
	cout << dp[N] << "\n";
}

int main(void)
{
	Prologue();
	input();
	solve();
	output();
}