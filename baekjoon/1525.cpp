#include <unistd.h>

#include "bits/stdc++.h"

using namespace std;

queue<pair<string, int> > Box;
set<string> Visit;

string Start, End;
int Min;

int di[] = {0, 0, 1, -1};
int dj[] = {1, -1, 0, 0};

void printMap(string str)
{
	for (int i = 0; i < str.size(); i++)
	{
		printf("%3c", str[i]);
		if (i % 3 == 2)
			printf("\n");
	}
}

void input()
{
	End = "123456780";
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			int a;
			cin >> a;
			char tmp = a + '0';
			Start = Start + tmp;
		}
	}
#if DEBUG
	printMap(Start);
#endif
	Box.push(make_pair(Start, 0));
	Visit.insert(Start);
}

void solve()
{
	while (!Box.empty())
	{
		string currStr = Box.front().first;
		int currCnt = Box.front().second;
#if DEBUG
		printf("level: %d\n", currCnt);
		printMap(currStr);
#endif
		Box.pop();

		if (currStr == End)
		{
			Min = currCnt;
			return;
		}

		int zeroOffset = currStr.find('0');
		int i = zeroOffset / 3;
		int j = zeroOffset % 3;

		for (int k = 0; k < 4; k++)
		{
			int ni = i + di[k];
			int nj = j + dj[k];
			if (ni >= 0 && nj >= 0 && ni < 3 && nj < 3)
			{
				string nextStr = currStr;
				swap(nextStr[i * 3 + j], nextStr[ni * 3 + nj]);
				if (Visit.find(nextStr) == Visit.end())
				{
					Visit.insert(nextStr);
					Box.push(make_pair(nextStr, currCnt + 1));
				}
			}
		}
#if DEBUG == 2
		usleep(1000000);
#endif
	}
	Min = -1;
}

void output()
{
#if DEBUG
	printf("Min: ");
#endif
	printf("%d\n", Min);
}

int main(void)
{
	input();
	solve();
	output();
}