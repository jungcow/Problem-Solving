#include <iostream>
#include <unordered_set>

#include "bits/stdc++.h"
using namespace std;

#define FAIL 0
#define SUCCESS 1

int TestCycle;

vector<bool> Answer;

int N;


void prologue(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
}

void each(void)
{
	unordered_set<int> Xset;
	unordered_set<int> Yset;

	int a, b;
	for (int i = 0; i < N; i++)
	{
		cin >> a >> b;

		Xset.insert(a);
		Yset.insert(b);
	}
	int total_pair = Xset.size() * Yset.size();
#if DEBUG
	cout << "total pair: " << total_pair << " N: " << N << "\n";
#endif
	if (N != total_pair)
		Answer.push_back(FAIL);
	else
		Answer.push_back(SUCCESS);
}

void input_and_solve(void)
{
	cin >> TestCycle;
	for (int i = 0; i < TestCycle; i++)
	{
		cin >> N;
		each();
	}
}

void output(void)
{
	for (int i = 0; i < Answer.size(); i++)
	{
		if (Answer[i])
			cout << "BALANCED\n";
		else
			cout << "NOT BALANCED\n";
	}
}

int main(void)
{
	prologue();
	input_and_solve();
	output();
}