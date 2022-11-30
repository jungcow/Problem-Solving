#include <bits/stdc++.h>

using namespace std;

vector<int> DP[51];

int N, M;

int P[10];
int MaxCost;
int Digits[10];

void Prologue(void)
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
}

void printVector(void)
{
	for (int i = 0; i <= M; i++)
	{
		if (DP[i].size())
			cout << i << ": ";
		for (int j = 0; j < DP[i].size(); j++)
		{
			cout << DP[i][j] << " ";
		}
		if (DP[i].size())
			cout << "\n";
	}
	cout << "\n";
}

void input(void)
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> P[i];
		if (P[i] > MaxCost)
			MaxCost = P[i];
		cout << "P[" << i << "]: " << P[i] << "\n";
	}
	for (int i = N - 1; i >= 0; i--)
		if (DP[P[i]].empty())
			DP[P[i]].push_back(i);
	cout << "\n";
	cin >> M;
#if DEBUG
	printVector();
#endif
}

void solve(void)
{
	// 1. 더 작은 값으로 더 많은 자릿수를 만들 수 있다면 이것이 정답
	/*
	6 -> 0
	7 -> 1
	8 -> 2
	9 -> X
	12 -> 00
	13 -> 10
	14 -> 20 // 11
	15 -> 21
	16 -> 22
	17 ->
	18 -> 000
	19 -> 100 //
	20 -> 200 // 110
	21 ->
	*/

	// 6, 7, 8원이 있으면 9원부터 DP 시작
	cout << "start\n";
	for (int i = MaxCost + 1; i <= M; i++)
	{
		int max = N - 1;
		int flag = false;
		for (int j = N - 2; j >= 0; j--)
		{
			// cout << i - P[j] << " ";
			if (i - P[j] >= 0 && DP[i - P[j]].size())
			{
				flag = true;
				cout << "max cost: " << i - P[max] << ", curr cost: " << i - P[j] << "\n";
				if (lexicographical_compare(DP[i - P[max]].begin(), DP[i - P[max]].end(),
											DP[i - P[j]].begin(), DP[i - P[j]].end()))
				{
					max = j;
					cout << "-> max P num: " << max << "\n";
				}
			}
		}
		cout << "\n";
		if (flag)
		{
			DP[i] = DP[i - P[max]];
			DP[i].push_back(max);
			sort(DP[i].rbegin(), DP[i].rend());
		}
#if DEBUG
		printVector();
#endif
	}
}

void output(void)
{
	for (int i = M; i >= 0; i--)
	{
		if (DP[i].size())
		{
			size_t size = DP[i].size();
			for (size_t j = 0; j < size; j++)
			{
				cout << DP[i][j];
			}
			break;
		}
	}
	cout << "\n";
}

int main(void)
{
	Prologue();
	input();
	solve();
	output();
}
