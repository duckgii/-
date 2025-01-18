#include <queue>
#include <utility>
#include <queue>
#include <algorithm>
#include <iostream>

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
	fill(&block[0][0], &block[200][200], 0);
	point1 = 0;
	point2 = 0;
	block1 = 0;
	block2 = 0;
}

int	checkVerti()
{
	int flag = 0;

	for (int i = 0; i < WIDTH; i++)
	{
		int count = 0;
		int start;
		int kind;
		for (int j = 1; j <= block[i][0]; j++)
		{
			if (count == 0)
			{
				start = j;
				kind = block[i][j] % 3;
				count++;
			}
			else if (block[i][j] % 3 == kind)
				count++;
			else
			{
				if (count >= 5)
				{
					for (int idx = start; idx < j; idx++)
					{
						block[i][idx] = kind + 3;
					}
					flag = 1;
				}
				kind = block[i][j] % 3;
				count = 1;
				start = j;
			}
		}
		if (count >= 5)
		{
			for (int idx = start; idx <= block[i][0]; idx++)
			{
				block[i][idx] = kind + 3;
			}
			flag = 1;
		}
		count = 0;
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

	for (int j = 1; j <= h; j++)
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
						block[idx][j] = kind + 3;
					}
					flag = 1;
				}
				count = 0;
				continue;
			}
			if (count == 0)
			{
				start = i;
				kind = block[i][j] % 3;
				count++;
				continue;
			}
			if (block[i][j] % 3 == kind)
			{
				count++;
			}
			else
			{
				if (count >= 5)
				{
					for (int idx = start; idx < i; idx++)
					{
						block[idx][j] = kind + 3;
					}
					flag = 1;
				}
				start = i;
				kind = block[i][j] % 3;
				count = 1;
			}
		}
		if (count >= 5)
		{
			for (int idx = start; idx < WIDTH; idx++)
			{
				block[idx][j] = kind + 3;
			}
			flag = 1;
		}
		count = 0;
	}
	return (flag);
}

int	checkRightUp() 
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
		
		for (int j = 1; j <= h; j++)
		{
			if (block[i + j - 1][j] == 0)
			{
				if (count >= 5)
				{
					for (int idx = start; idx < j; idx++)
					{
						block[i + idx - 1][idx] = kind + 3;
					}
					flag = 1;
				}
				count = 0;
			}
			else if (count == 0)
			{
				start = j;
				kind = block[i + j - 1][j] % 3;
				count++;
			}
			else if (block[i + j - 1][j] % 3 == kind)
				count++;
			else
			{
				if (count >= 5)
				{
					for (int idx = start; idx < j; idx++)
					{
						block[i + idx - 1][idx] = kind + 3;
					}
					flag = 1;
				}
				kind = block[i + j - 1][j] % 3;
				start = j;
				count = 1;
			}
		}
		if (count >= 5)
		{
			for (int idx = 0; idx < count; idx++)
			{
				block[i + idx + start - 1][start + idx] = kind + 3;
			}
			flag = 1;
		}
		count = 0;
	}


	for (int j = 1; j <= h; j++)
	{
		int count = 0;
		int kind, start;
		for (int jj = 0; jj <= h; jj++)
		{
			if (j + jj > h)
				break;
			if (block[jj][j + jj] == 0)
			{
				if (count >= 5)
				{
					for (int idx = start; idx < jj; idx++)
					{
						block[idx][j + idx] = kind + 3;
					}
					flag = 1;
				}
				count = 0;
			}
			else if (count == 0)
			{
				start = jj;
				kind = block[jj][j + jj] % 3;
				count++;
			}
			else if (block[jj][j + jj] % 3 == kind)
				count++;
			else
			{
				if (count >= 5)
				{
					for (int idx = start; idx < jj; idx++)
					{
						block[idx][j + idx] = kind + 3;
					}
					flag = 1;
				}
				kind = block[jj][j + jj] % 3;
				start = jj;
				count = 1;
			}
		}
		if (count >= 5)
		{
			for (int idx = 0; idx < count; idx++)
			{
				block[start + idx][j + start + idx] = kind + 3;
			}
			flag = 1;
		}
		count = 0;
	}
	return (flag);
}

int	checkLeftUp() 
{
	int flag = 0;
	int	h = 0;

	for (int i = 0; i < WIDTH; i++)
	{
		h = max(h, block[i][0]);
	}

	for (int i = WIDTH; i >= 0; i--)
	{
		int x = i;
		int count = 0;
		int kind, start;
		
		for (int j = 1; j <= h; j++)
		{
			if (i - j < 0)
				break;
			if (block[i - j][j] == 0)
			{
				if (count >= 5)
				{
					for (int idx = start; idx < j; idx++)
					{
						block[i - idx][idx] = kind + 3;
					}
					flag = 1;
				}
				count = 0;
			}
			else if (count == 0)
			{
				start = j;
				kind = block[i - j][j] % 3;
				count++;
			}
			else if (block[i - j][j] % 3 == kind)
				count++;
			else
			{
				if (count >= 5)
				{
					for (int idx = start; idx < j; idx++)
					{
						block[i - idx][idx] = kind + 3;
					}
					flag = 1;
				}
				kind = block[i - j][j] % 3;
				count = 1;
				start = j;
			}
		}
		if (count >= 5)
		{
			for (int idx = 0; idx < count; idx++)
			{
				block[i - (idx + start)][idx + start] = kind + 3;
			}
			flag = 1;
		}
	}


	for (int j = 1; j <= h; j++)
	{
		int x = WIDTH - 1;
		int count = 0;
		int kind, start;
		for (int jj = 0; jj <= h; jj++)
		{
			if (x - jj < 0 || j + jj > h)
				break;
			if (block[x - jj][j + jj] == 0)
			{
				if (count >= 5)
				{
					for (int idx = start; idx < jj; idx++)
					{
						block[x - idx][j + idx] = kind + 3;
					}
					flag = 1;
				}
				count = 0;
			}
			else if (count == 0)
			{
				start = jj;
				kind = block[x - jj][j + jj] % 3;
				count++;
			}
			else if (block[x - jj][j + jj] % 3 == kind)
				count++;
			else
			{
				if (count >= 5)
				{
					for (int idx = start; idx < jj; idx++)
					{
						block[x - idx][j + idx] = kind + 3;
					}
					flag = 1;
				}
				kind = block[x - jj][j + jj] % 3;
				start = jj;
				count = 1;
			}
		}
		if (count >= 5)
		{
			for (int idx = 0; idx < count; idx++)
			{
				block[x - (start + idx)][j + start + idx] = kind + 3;
			}
			flag = 1;
		}
		count = 0;
	}
	return (flag);
}

int	addpoint(int mPlayer)
{
	int b1 = 0;
	int b2 = 0;
	int point = 0;

	for (int i = 0; i < WIDTH; i++)
	{
		int count = 0;
		int h = block[i][0];
		for (int j = 1; j <= h; j++)
		{
			if (block[i][j] > 2)
			{
				if (block[i][j] == mPlayer + 3)
					point++;
				if (block[i][j] == 4)
					b1++;
				if (block[i][j] == 5)
					b2++;
				count++;
				block[i][j] = 0;
				continue;
			}
			if (count > 0)
			{
				block[i][j - count] = block[i][j];
				block[i][j] = 0;
			}
		}
		block[i][0] -= count;
	}
	block1 -= b1;
	block2 -= b2;
	return (point);
}


int dropBlocks(int mPlayer, int mCol)
{
	int ret = 0;
	int flag = 1;
	for (int i = 0; i < 3; i++)
	{
		block[mCol + i][++block[mCol + i][0]] = mPlayer;
	}
	if (mPlayer == 1)
		block1 += 3;
	else
		block2 += 3;
	while (flag)
	{
		flag = 0;
		if (checkHori())
			flag = 1;
		if (checkVerti())
			flag = 1;
		if (checkRightUp())
			flag = 1;
		if (checkLeftUp())
			flag = 1;
		
		ret += addpoint(mPlayer);

	}
	if (mPlayer == 1)
		point1 += ret;
	else
		point2 += ret;
	return ret;
}

int changeBlocks(int mPlayer, int mCol)
{
	queue<pair<int, int> >	bfs;
	int ret = 0;
	int kind = block[mCol][1] % 3;
	int i = mCol; 
	int j = 1;
	int diff;
	int flag = 1;
	int count = 0;

	if (mPlayer == 1)
		diff = 2;
	else
		diff = 1;
	if (kind == diff)
	{
		bfs.push({mCol, 1});
		block[mCol][1] = mPlayer;
	}
	while (bfs.size() > 0)
	{
		i = bfs.front().first;
		j = bfs.front().second;
		count++;
		bfs.pop();
		if (i - 1 >= 0 && block[i - 1][j] % 3 == kind)
		{
			bfs.push({i - 1, j});
			block[i - 1][j] = mPlayer;
		}
		if (i + 1 < WIDTH && block[i + 1][j] % 3 == kind)
		{
			bfs.push({i + 1, j});
			block[i + 1][j] = mPlayer;
		}
		if (j - 1 > 0 && block[i][j - 1] % 3 == kind)
		{
			bfs.push({i, j - 1});
			block[i][j - 1] = mPlayer;
		}
		if (j + 1 <= HEIGHT && block[i][j + 1] % 3 == kind)
		{
			bfs.push({i, j + 1});
			block[i][j + 1] = mPlayer;
		}
	}
	while (flag)
	{
		flag = 0;
		if (checkHori())
			flag = 1;
		if (checkVerti())
			flag = 1;
		if (checkRightUp())
			flag = 1;
		if (checkLeftUp())
			flag = 1;
		
		ret += addpoint(mPlayer);

	}
	if (mPlayer == 1)
	{
		point1 += ret;
		block1 += count;
		block2 -= count;
	}
	else
	{
		point2 += ret;
		block2 += count;
		block1 -= count;
	}
	return ret;
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
