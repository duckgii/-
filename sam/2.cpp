#include <queue>
#include <utility>
#include <queue>
#include <algorithm>

int	WIDTH;
int	HEIGHT;
int block[201][201];
int point1;
int point2;
int block1;
int block2;

using namespace std;

void init(int W, int H)
{
	WIDTH = W;
	HEIGHT = H;
}

int	checkVerti()
{
	int	h;
	int flag = 0;

	for (int i = 0; i < WIDTH; i++)
	{
		h = block[i][0];
		int count = 0;
		int start;
		int kind;
		for (int j = 1; j < h; j++)
		{
			if (count == 0)
			{
				start = j;
				kind = block[i][j];
				count++;
			}
			else if (block[i][j] == kind)
				count++;
			else
			{
				if (count >= 5)
				{
					for (int idx = start; idx < j; idx++)
					{
						block[i][idx] = kind + 2;
					}
					flag = 1;
				}
				count = 0;

			}
		}
	}
	return (flag);
}

int	checkHori()
{
	int	h = 0;
	int flag = 0;
	for (int i = 0; i < WIDTH; i++)
	{
		h = max(h, block[i][0]);
	}

	for (int j = 1; j < h; j++)
	{
		int count = 0;
		int start;
		int kind;
		for (int i = 0; i < WIDTH; i++)
		{
			if (block[i][j] == 0)
			{
				if (count >= 5)
				{
					for (int idx = start; idx < i; idx++)
					{
						block[idx][j] = kind + 2;
					}
					flag = 1;
				}
				count = 0;
			}
			else if (count == 0)
			{
				start = i;
				kind = block[i][j];
				count++;
			}
			else if (block[i][j] == kind)
				count++;
			else
			{
				if (count >= 5)
				{
					for (int idx = start; idx < i; idx++)
					{
						block[idx][j] = kind + 2;
					}
					flag = 1;
				}
				count = 0;
			}
		}
	}
	return (flag);
}

int	checkRightUP()
{
	int flag = 0;
	int	h = 0;

	for (int i = 0; i < WIDTH; i++)
	{
		h = max(h, block[i][0]);
	}

	for (int i = 0; i < WIDTH; i++)
	{
		int x = i;
		int count = 0;
		int kind, start;
		
		for (int j = 1; j < h; j++)
		{
			if (block[i + j - 1][j] == 0)
			{
				if (count >= 5)
				{
					for (int idx = start; idx < j; idx++)
					{
						block[i + start - 1][start] = kind + 2;
					}
					flag = 1;
				}
				count = 0;
			}
			else if (count == 0)
			{
				start = i;
				kind = block[i + j - 1][j];
				count++;
			}
			else if (block[i + j - 1][j] == kind)
				count++;
			else
			{
				if (count >= 5)
				{
					for (int idx = start; idx < j; idx++)
					{
						block[i + start - 1][start] = kind + 2;
					}
					flag = 1;
				}
				count = 0;
			}
		}
	}
	return (flag);
}

int	checkLeftUp();

int	addpoint(int mPlayer);


int dropBlocks(int mPlayer, int mCol)
{
	for (int i = 0; i < 3; i++)
	{
		block[mCol + i][block[mCol + i][0]++] = mPlayer;
	}
	if (mPlayer == 1)
		block1 += 3;
	else
		block2 += 3;
	if (checkHori() || checkVerti()|| checkRightUp() || checkLeftUp())
		return (addpoint(mPlayer));
	return 0;
}

int changeBlocks(int mPlayer, int mCol)
{
	queue<pair<int, int>>	bfs;

	bfs.push({mCol, 1});
	while (bfs.size())
	{

	}
	if (checkHori() || checkVerti()|| checkRightUp() || checkLeftUp())
		return (addpoint(mPlayer));
	return 0;
}


int getResult(int mBlockCnt[2])
{
	mBlockCnt[0] = block1;
	mBlockCnt[1] = block2;
	if (point1 == point2)
		return (0);
	if (point1 > point2)
		return (1);
	return (2);
}
