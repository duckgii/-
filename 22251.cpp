#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int	diff[10][10];
int ret = 0;
int display, now;
int limit;
int ele[10000000];

void	solv(int check,  int t_now, int upside, int num)
{
	int	calc = t_now % 10;

	t_now /= 10;
	if (check == display && upside >= 0)
	{
		if (ele[num] == 0 && num <= limit &&  num != now)
		{
			ele[num] = 1;
		}
		return;
	}
	for (int i = 0; i <= 9; i++)
	{
		if (diff[calc][i] <= upside)
		{
			solv(check + 1, t_now, upside - diff[calc][i], num + i * pow(10, check));
		}
	}
}

int main()
{
	int upside;
	bool flag = true;
	int	led[10][7] = {{1, 1, 1, 0, 1, 1, 1}, \
					{0, 0, 1, 0, 0, 1, 0}, \
					{1, 0, 1, 1, 1, 0, 1}, \
					{1, 0, 1, 1, 0, 1, 1}, \
					{0, 1, 1, 1, 0, 1, 0}, \
					{1, 1, 0, 1, 0, 1, 1}, \
					{1, 1, 0, 1, 1, 1, 1}, \
					{1, 0, 1, 0, 0, 1, 0}, \
					{1, 1, 1, 1, 1, 1, 1}, \
					{1, 1, 1, 1, 0, 1, 1}};


	cin>>limit>>display>>upside>>now;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			int count = 0;
			for (int k = 0; k < 7; k++)
			{
				if (led[i][k] != led[j][k])
					count++;
			}
			if (i == j)
				count = 0;// ㅇㅕ기 때문에 한참을 헤맸다 -> 현재 숫자와 동일한 숫자는 할 수 없도록 1000으로 설정했었는데 한 자리만 다르면 다른 숫자이므로 이렇게 접근하면 안된다.
			diff[i][j] = count;
		}
	}
	solv(0, now, upside, 0);
	for (int i = 1; i <= limit; i++)
	{
		if (ele[i] == 1 && i != now)
		{
			ret++;
		}
	}
	cout<<ret<<endl;
}
