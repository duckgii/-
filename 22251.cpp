#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int	diff[10][10];
int ret = 0;
int display;
int limit;
int ele[10000000];
void	solv(int check,  int t_now, int upside, int num)
{
	int	calc = t_now % 10;
	int flag = true;

	t_now /= 10;
	if (check == display || upside == 0)
	{
		if (ele[num] == 0 && num <= limit)
		{
			ele[num] = 1;
			cout<<num<<endl;
		}
		return;
	}
	for (int i = 0; i <= 9; i++)
	{
		//solv(check + 1, t_now, upside, num + calc* 10);
		if (diff[calc][i] <= upside)
		{
			solv(check + 1, t_now, upside - diff[calc][i], num + i * pow(10, check));
		}
	}
	solv(check + 1, t_now, upside, num + calc * 10);
}

int main()
{
	int upside, now;
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
			for (int k =0; k < 7; k++)
			{
				if (led[i][k] != led[j][k])
					count++;
			}
			if (i == j)
				count = 1000;
			diff[i][j] = count;
		}
	}
	solv(0, now, upside, 0);
	for (int i = 1; i <= limit; i++)
	{
		if (ele[i] == 1)
			ret++;
	}
	cout<<ret<<endl;
}

// 0 0 0
// 1   2
// 3 3 3   
// 4   5
// 6 6 6 
//  _
// |_|
// |_|
//


/*
30
20
1
32
33
3
13
23
43
34
24
36
6
16
26
46
37
27
38
8
18
28
48
39
9
19
29
27
*/
/*
3
5
6
8
9
13
15
16
18
19
20
23
24
25
26
28
29
30
31
32
33
34
36
37
38
39
43
45
46
48
*/