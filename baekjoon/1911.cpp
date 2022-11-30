#include <bits/stdc++.h>

using namespace std;
#define MAX 10001

unsigned long long N, L;
int Min;

vector<pair<int, int> > water;

void Prologue(void)
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
}

void input(void)
{
	cin >> N >> L;
	for (int i = 0; i < N; i++)
	{
		int s, e;
		cin >> s >> e;
		water.push_back(make_pair(s, e));
	}
}

void sorting_water(void)
{
	sort(water.begin(), water.end());
}

void line_sweeping(void)
{
	int num = 0;
	size_t size = water.size();
	int i = -1;
	unsigned int currOffset = 0;
	while (++i < size)
	{
		int begin = water[i].first;
		int end = water[i].second;
		/*
			- [begin,end,curr] pass -> i++; currOffset;
			- [begin,curr,end] 이면 [curr-end]에 대한 널빤지 갯수 구함 ->  i++; currOffset = begin + forAdding * L
			- [curr,begin,end] 이면 [begin-end]에 대한 널빤지 갯수 구하기 -> i++; currOffset = begin + forAdding * L
		*/
		if (end <= currOffset)
			continue;
		if (currOffset > begin)
			begin = currOffset;
		int length = end - begin;
		int forAdding = length / L;
		if (length % L)
			forAdding += 1;
		num += forAdding;
		currOffset = begin + forAdding * L;
	}
	Min = num;
}

void solve(void)
{
	sorting_water();
	line_sweeping();
}

void output(void)
{
	cout << Min << "\n";
}

int main(void)
{
	Prologue();
	input();
	solve();
	output();
}
