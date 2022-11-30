#include <bits/stdc++.h>

using namespace std;

int N, Q;

pair<int, int> Pair[100001];

void Prologue(void)
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
}

void input(void)
{
	cin >> N >> Q;
	for (int i = 0; i < Q; i++)
	{
		int t, a;
		cin >> t >> a;
		Pair[i] = make_pair(t, a);
	}
}

void solve(void)
{
	if (Q < N)
		return;
	for (int i = 0; i < Q; i++)
	{
        
	}
}

void output(void)
{
	if (Q < N)
		cout << Q << "\n";
	else
		cout << " "
			 << "\n";
}

int main(void)
{
	Prologue();
	input();
	solve();
	output();
}