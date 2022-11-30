#include <bits/stdc++.h>

using namespace std;

int N;
int Answer;
int top;
int bottom;

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

void solve(void)
{
	Answer = N == 1 ? 1 : 2 * N - 2;
	top = (Answer + 2) / 2 - 2;
	bottom = Answer - top;
}

void output(void)
{
	cout << Answer << "\n";
	if (Answer == 1)
	{
		cout << "1 1\n";
		return;
	}
	for (int i = 0; i < top; i++)
		cout << "1 " << i + 1 << "\n";
	for (int i = 0; i < bottom; i++)
		cout << N << " " << i + 1 << "\n";
}

int main(void)
{
	Prologue();
	input();
	solve();
	output();
}