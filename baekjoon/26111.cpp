#include <bits/stdc++.h>

using namespace std;

stack<char> Stack;
unsigned long long LevelSum;

void Prologue(void)
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
}

void input_and_solve(void)
{
	string str;
	int prev = 0;

	cin >> str;
	for (int i = 0; i < str.size(); i++)
	{
		int a = str[i];
		if (a == '(')
			Stack.push(a);
		else if (a == ')')
		{
			if (Stack.empty())
				return;
			Stack.pop();
			if (prev != ')')
			{
#if DEBUG
				cout << "leaf level: " << Stack.size() << "\n";
#endif
				LevelSum += Stack.size();
			}
		}
		prev = a;
	}
}

void output(void)
{
	cout << LevelSum << "\n";
}

int main(void)
{
	Prologue();
	input_and_solve();
	output();
}