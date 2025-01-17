#include <utility>
#include <iostream>

using namespace std;

int	big = 0;
int	small = 0;
int bigCount;

#define MAX_N 1000
#define MAX_M 20

int input[MAX_N][MAX_N];
pair<int, int> spots[10000];

struct Result {
	int y, x;
};

void init(int N, int M, int Map[MAX_N][MAX_N])
{
	big = N;
	small = M;
	int idx = 0;

	for (int i = 0; i < MAX_N; i++)
	{
		for (int j = 0; j < MAX_N; j++)
		{
			input[i][j] = Map[i][j];
			if (input[i][j] == 1)
			{
				spots[idx] = {i, j};
				idx++;
			}
		}
	}
	bigCount = idx;
}

Result findTreasureChest(int Pieces[MAX_M][MAX_M])
{
	Result res;
	pair<int, int>	smallSpots[20];
	int idx = 0;
	int idx_x, idx_y;
	int i_x, i_y;
	int check[20];
	int smallSpotsCount = 0;
	int diff_x, diff_y;
	int x, y, flag;

	for (int i = 0; i < small; i++)
	{
		for (int j = 0; j < small; j++)
		{
			if (Pieces[i][j] != 0)
			{
				if (Pieces[i][j] == 1)
				{
					smallSpots[idx] = {i, j};
					smallSpotsCount++;
					idx++;
				}
				else
				{
					idx_y = i;
					idx_x = j;
				}
			}
		}
	}
	for (int i = 0; i < smallSpotsCount; i++)
	{
		smallSpots[i].first -= idx_y;
		smallSpots[i].second -= idx_x;
	}

	for (int _ = 0; _ < 4; _++)
	{
		for (int i = 0; i < bigCount; i++)
		{
			bool flag = true;

			y = spots[i].first;
			x = spots[i].second;
			if (input[y][x] == 0)
				continue;
			for (int j = 0; j < smallSpotsCount; j++)
			{
				i_y = y + smallSpots[j].first;
				i_x = x + smallSpots[j].second;
				if (i_y < 0 || i_x < 0 || i_y >= big || i_x >= big || input[i_y][i_x] == 0)
				{
					flag = false;
					break;
				}
			}
			if (flag == true)
			{
				for (int j = 0; j < smallSpotsCount; j++)
				{
					input[y + smallSpots[j].first][x + smallSpots[j].second] = 0;
				}
				input[y][x] = 0;
				res.y = spots[i].first;
				res.x = spots[i].second;
				return res;
			}
		}
		for (int i = 0; i < smallSpotsCount; i++)
		{
			smallSpots[i] = {smallSpots[i].second, smallSpots[i].first * -1};
		}
	}
	return res;
}