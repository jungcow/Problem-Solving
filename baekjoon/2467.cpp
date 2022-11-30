#include <bits/stdc++.h>

using namespace std;

#define MAX 100001

int N;
long long Input[MAX];
unsigned long long Min;
long long Answer1, Answer2;

void printArray(void)
{
	for (int i = 1; i <= N; i++)
	{
		cout << Input[i] << " ";
	}
	cout << "\n";
}

void Prologue(void)
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
}

void input(void)
{
	Min = -1;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> Input[i];
	}
#if DEBUG
	printArray();
#endif
}

unsigned long long getAbs(long long i)
{
	return i < 0 ? -1 * i : i;
}

void solve(void)
{
	int p1, p2;
	p1 = 1;
	p2 = N;
	while (p1 < p2)
	{
		long long tmp = Input[p1] + Input[p2];
		unsigned long long ab = getAbs(tmp);
		if (Min > ab)
		{
			Min = ab;
			Answer1 = Input[p1];
			Answer2 = Input[p2];
#if DEBUG
			cout << "update v1: " << Answer1 << ", v2: " << Answer2 << "\n";
#endif
		}
		tmp < 0 ? p1++ : p2--;
	}
}

void output(void)
{
	cout << Answer1 << " " << Answer2 << "\n";
}

int main(void)
{
	Prologue();
	input();
	solve();
	output();
}