#include <bits/stdc++.h>

#include <unordered_set>

using namespace std;
#define MAX 20

unordered_set<unsigned int> Set;

int N, M, R, Sum;

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
	for (int i = 0; i < N; i++)
	{
		cin >> Input[i];
		M += Input[i];
	}
}

void nCr(int count, int start)
{
	if (count == R)
	{
		Set.insert(Sum);
#if DEBUG
		printf("\nsum : %d\n", Sum);
#endif
		Sum = 0;
		return;
	}

	for (int i = start; i < N; i++)
	{
#if DEBUG
		printf("%d ", Input[i]);
#endif
		Sum += Input[i];
		nCr(count + 1, start + 1);
	}
}

void solve(void)
{
	for (int i = 0; i < N; i++)
	{
		R = i;
		nCr(0, 0);
	}
}

void output(void)
{
	printf("%lu\n", M - Set.size());
}

int main(void)
{
	Prologue();
	input();
	solve();
	output();
}