#include "bits/stdc++.h"

using namespace std;

#define WALL 90000
int arr[502][502];

typedef pair<int, int> coord;
vector<pair<coord, int[4]> > vec;
vector<pair<int, vector<int> > > vec2;
stack<int> st;

void printmap(int M, int N)
{
	for (int i = 0; i <= M + 1; i++)
	{
		for (int j = 0; j <= N + 1; j++)
		{
			printf("%6d", arr[i][j]);
		}
		printf("\n");
	}
}

void initmap(int M, int N)
{
	for (int i = 0; i < 502; i++)
		for (int j = 0; j < 502; j++)
			arr[i][j] = WALL;
	for (int i = 1; i <= M; i++)
		for (int j = 1; j <= N; j++)
			cin >> arr[i][j];
}

void initgraph(int M, int N)
{
	for (int i = M; i >= 1; i--)
	{
		for (int j = N; j >= 1; j--)
		{
			vector<int> tmp;
			if ((arr[i - 1][j] != WALL) && (arr[i][j] < arr[i - 1][j]))
				tmp.push_back(arr[i - 1][j]);
			if ((arr[i + 1][j] != WALL) && (arr[i][j] < arr[i + 1][j]))
				tmp.push_back(arr[i + 1][j]);
			if ((arr[i][j - 1] != WALL) && (arr[i][j] < arr[i][j - 1]))
				tmp.push_back(arr[i][j - 1]);
			if ((arr[i][j + 1] != WALL) && (arr[i][j] < arr[i][j + 1]))
				tmp.push_back(arr[i][j + 1]);
			vec2.push_back(make_pair(arr[i][j], tmp));
		}
	}
}

void solve()
{
	int root = 0;
	for (int i = 0; i <= vec2.size(); i++)
	{
		root +=
		// for (int j = 0; j <= vec2[i].second.size(); j++)
		// {
		// 	root
		// }
	}
}

int main(void)
{
	int M, N;
	cin >> M >> N;
	std::cout << "M: " << M << "N: " << N << endl;
	initmap(M, N);
	printmap(M, N);
	initgraph(M, N);

	solve();
	return (0);
}