#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool flag = false;
void	sol(vector<int> &alpha, vector<int> &input)
{
	string	last = ".........\n.........\n.........\n.........\n.........\n";

	if (flag)
		return;
	for (int i = 0; i < 12; i++)
	{
		if (input[i] == -1)
		{
			for (int j = 0; j < 12; j++)
			{
				if (alpha[j] ==  -1)
				{
					alpha[j] = 1;
					input[i] = j;
					sol(alpha, input);
					alpha[j] = -1;
					input[i] = -1;
				}
			}
			return;
		}
	}
	for (int i = 0; i < 12; i++)
	{
		if (input[i] == -1)
			return;
	}
	last[4] = input[0] + 'A';	last[11] = input[1] + 'A';	last[13] = input[2] + 'A';	last[15] = input[3] + 'A';	last[17] = input[4] + 'A';	last[22] = input[5] + 'A';
	last[26] = input[6] + 'A';	last[31] = input[7] + 'A';	last[33] = input[8] + 'A';	last[35] = input[9] + 'A';	last[37] = input[10] + 'A';	last[44] = input[11] + 'A';
	if (input[7] + input[8] + input[9] + input[10] == 22 && input[0] + input[2] + input[5] + input[7] == 22 && input[0] + input[3] + input[6] + input[10] == 22 \
		&& input[1] + input[5] + input[8] + input[11] == 22 && input[4] + input[6] + input[9] + input[11] == 22 && input[1] + input[2] + input[3] + input[4] == 22 && flag != true)
	{
		cout<<last;
		flag = true;
	}
}

int main()
{
	vector<string> temp(5);
	vector<int>	input(12);
	vector<int>	alpha(12);

	fill(alpha.begin(), alpha.end(), -1);
	for (int i = 0; i < 5; i++)
	{
		cin>>temp[i];
		for (int j = 0; j < 9; j++)
		{
			if (temp[i][j] >= 'A' && temp[i][j] <= 'L')
			{
				alpha[temp[i][j] - 'A'] = 1;
			}
		}
	}
	input[0] = temp[0][4] - 'A';input[1] = temp[1][1] - 'A';input[2] = temp[1][3] - 'A';input[3] = temp[1][5] - 'A';input[4] = temp[1][7] - 'A';input[5] = temp[2][2] - 'A';
	input[6] = temp[2][6] - 'A';input[7] = temp[3][1] - 'A';input[8] = temp[3][3] - 'A';input[9] = temp[3][5] - 'A';input[10] = temp[3][7] - 'A';input[11] = temp[4][4] - 'A';
	for (int i = 0; i < 12; i++)
	{
		if (input[i] > 12)
			input[i] = -1;
	}
	sol(alpha, input);
}

// ....1....
// .2.3.4.5.
// ..6...7..
// .8.9.10.11.
// ....12....
