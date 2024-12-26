#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string>	ret;

void	sol(vector<int>alpha, vector<int>check, vector<int> input)
{
	int count = 0;
	int	remain = 0;
	vector<int>	t_alpha = alpha;
	vector<int>	t_check = check;
	vector<int>	t_input = input;
	string	last = ".........\n.........\n.........\n.........\n.........\n";

	cout<<"hi"<<endl;
	for (int i = 0; i < 12; i++)
	{
		cout<<input[i]<<" ";
		if (input[i] == 0)
		{
			for (int j = 0; j < 12; j++)
			{
				t_alpha = alpha;
				t_check = check;
				t_input = input;
				if (alpha[j] == 0)
				{
					t_alpha[j] = 1;
					t_input[i] = j + 1;
					sol(t_alpha, t_check, t_input);
				}
			}
		}
	}
	for (int i = 0; i < 12; i++)
	{
		if (input[i] == 0)
			return;
	}

	//for (int i = 0; i < 12; i++)
	//{
	//	cout<<static_cast<char>(input[i] + 'A' - 1)<<" ";
	//}
	//cout<<endl;
	//if (check[0] < 26)
	//{
	//	if (input[0] == 0)
	//	{
	//		for (int i = 0; i < 12; i++)
	//		{
	//			t_alpha = alpha;
	//			t_input = input;
	//			t_check = check;
	//			if (t_alpha[i] == 0)
	//			{
	//				t_alpha[i] = 1;
	//				t_check[0] += i + 1;
	//				t_input[0] = i + 1;
	//				sol(t_alpha, t_check, t_input);
	//			}
	//		}
	//		return;
	//	}
	//	if (input[2] == 0)
	//	{
	//		for (int i = 0; i < 12; i++)
	//		{
	//			t_alpha = alpha;
	//			t_input = input;
	//			t_check = check;
	//			if (t_alpha[i] == 0)
	//			{
	//				t_alpha[i] = 1;
	//				t_check[0] += i + 1;
	//				t_input[2] = i + 1;
	//				sol(t_alpha, t_check, t_input);
	//			}
	//		}
	//		return;
	//	}
	//	if (input[5] == 0)
	//	{
	//		for (int i = 0; i < 12; i++)
	//		{
	//			t_alpha = alpha;
	//			t_input = input;
	//			t_check = check;
	//			if (t_alpha[i] == 0)
	//			{
	//				t_alpha[i] = 1;
	//				t_check[0] += i + 1;
	//				t_input[5] = i + 1;
	//				sol(t_alpha, t_check, t_input);
	//			}
	//		}
	//		return;
	//	}
	//	if (input[7] == 0)
	//	{
	//		for (int i = 0; i < 12; i++)
	//		{
	//			t_alpha = alpha;
	//			t_input = input;
	//			t_check = check;
	//			if (t_alpha[i] == 0)
	//			{
	//				t_alpha[i] = 1;
	//				t_check[0] += i + 1;
	//				t_input[7] = i + 1;
	//				sol(t_alpha, t_check, t_input);
	//			}
	//		}
	//		return;
	//	}
	//	return;
	//}
	//else if (check[0] > 26)
	//	return;
	//else
	//{
	//	if (t_input[0] * t_input[2] * t_input[5] * t_input[7] == 0)
	//		return;
	//}



	//if (check[1] < 26)
	//{
	//	if (input[7] == 0)
	//	{
	//		for (int i = 0; i < 12; i++)
	//		{
	//			t_alpha = alpha;
	//			t_input = input;
	//			t_check = check;
	//			if (t_alpha[i] == 0)
	//			{
	//				t_alpha[i] = 1;
	//				t_check[1] += i + 1;
	//				t_input[7] = i + 1;
	//				sol(t_alpha, t_check, t_input);
	//			}
	//		}
	//		return;
	//	}
	//	if (input[8] == 0)
	//	{
			
	//		for (int i = 0; i < 12; i++)
	//		{
	//			t_alpha = alpha;
	//			t_input = input;
	//			t_check = check;
	//			if (t_alpha[i] == 0)
	//			{
	//				t_alpha[i] = 1;
	//				t_check[1] += i + 1;
	//				t_input[8] = i + 1;
	//				sol(t_alpha, t_check, t_input);
	//			}
	//		}
	//		return;
	//	}
	//	if (input[9] == 0)
	//	{
	//		for (int i = 0; i < 12; i++)
	//		{
	//			t_alpha = alpha;
	//			t_input = input;
	//			t_check = check;
	//			if (t_alpha[i] == 0)
	//			{
	//				t_alpha[i] = 1;
	//				t_check[1] += i + 1;
	//				t_input[9] = i + 1;
	//				sol(t_alpha, t_check, t_input);
	//			}
	//		}
	//		return;
	//	}
	//	if (input[10] == 0)
	//	{
	//		for (int i = 0; i < 12; i++)
	//		{
	//			t_alpha = alpha;
	//			t_input = input;
	//			t_check = check;
	//			if (t_alpha[i] == 0)
	//			{
	//				t_alpha[i] = 1;
	//				t_check[1] += i + 1;
	//				t_input[10] = i + 1;
	//				sol(t_alpha, t_check, t_input);
	//			}
	//		}
	//		return;
	//	}
	//	return;
	//}
	//else if (check[1] > 26)
	//	return;
	//else
	//{
	//	if (t_input[7] * t_input[8] * t_input[9] * t_input[10] == 0)
	//		return;
	//}



	//if (check[2] < 26)
	//{
	//	if (input[0] == 0)
	//	{
	//		for (int i = 0; i < 12; i++)
	//		{
	//			t_alpha = alpha;
	//			t_input = input;
	//			t_check = check;
	//			if (t_alpha[i] == 0)
	//			{
	//				t_alpha[i] = 1;
	//				t_check[2] += i + 1;
	//				t_input[0] = i + 1;
	//				sol(t_alpha, t_check, t_input);
	//			}
	//		}
	//		return;
	//	}
	//	if (input[3] == 0)
	//	{
	//		for (int i = 0; i < 12; i++)
	//		{
	//			t_alpha = alpha;
	//			t_input = input;
	//			t_check = check;
	//			if (t_alpha[i] == 0)
	//			{
	//				t_alpha[i] = 1;
	//				t_check[2] += i + 1;
	//				t_input[3] = i + 1;
	//				sol(t_alpha, t_check, t_input);
	//			}
	//		}
	//		return;
	//	}
	//	if (input[6] == 0)
	//	{
	//		for (int i = 0; i < 12; i++)
	//		{
	//			t_alpha = alpha;
	//			t_input = input;
	//			t_check = check;
	//			if (t_alpha[i] == 0)
	//			{
	//				t_alpha[i] = 1;
	//				t_check[2] += i + 1;
	//				t_input[6] = i + 1;
	//				sol(t_alpha, t_check, t_input);
	//			}
	//		}
	//		return;
	//	}
	//	if (input[10] == 0)
	//	{
	//		for (int i = 0; i < 12; i++)
	//		{
	//			t_alpha = alpha;
	//			t_input = input;
	//			t_check = check;
	//			if (t_alpha[i] == 0)
	//			{
	//				t_alpha[i] = 1;
	//				t_check[2] += i + 1;
	//				t_input[10] = i + 1;
	//				sol(t_alpha, t_check, t_input);
	//			}
	//		}
	//		return;
	//	}
	//	return;
	//}
	//else if (check[2] > 26)
	//	return;
	//else
	//{
	//	if (t_input[0] * t_input[3] * t_input[6] * t_input[10] == 0)
	//		return;
	//}



	//if (check[3] < 26)
	//{
	//	if (input[1] == 0)
	//	{
	//		for (int i = 0; i < 12; i++)
	//		{
	//			t_alpha = alpha;
	//			t_input = input;
	//			t_check = check;
	//			if (t_alpha[i] == 0)
	//			{
	//				t_alpha[i] = 1;
	//				t_check[3] += i + 1;
	//				t_input[1] = i + 1;
	//				sol(t_alpha, t_check, t_input);
	//			}
	//		}
	//		return;
	//	}
	//	if (input[5] == 0)
	//	{
	//		for (int i = 0; i < 12; i++)
	//		{
	//			t_alpha = alpha;
	//			t_input = input;
	//			t_check = check;
	//			if (t_alpha[i] == 0)
	//			{
	//				t_alpha[i] = 1;
	//				t_check[3] += i + 1;
	//				t_input[5] = i + 1;
	//				sol(t_alpha, t_check, t_input);
	//			}
	//		}
	//		return;
	//	}
	//	if (input[8] == 0)
	//	{
	//		for (int i = 0; i < 12; i++)
	//		{
	//			t_alpha = alpha;
	//			t_input = input;
	//			t_check = check;
	//			if (t_alpha[i] == 0)
	//			{
	//				t_alpha[i] = 1;
	//				t_check[3] += i + 1;
	//				t_input[8] = i + 1;
	//				sol(t_alpha, t_check, t_input);
	//			}
	//		}
	//		return;
	//	}
	//	if (input[11] == 0)
	//	{
	//		for (int i = 0; i < 12; i++)
	//		{
	//			t_alpha = alpha;
	//			t_input = input;
	//			t_check = check;
	//			if (t_alpha[i] == 0)
	//			{
	//				t_alpha[i] = 1;
	//				t_check[3] += i + 1;
	//				t_input[11] = i + 1;
	//				sol(t_alpha, t_check, t_input);
	//			}
	//		}
	//		return;
	//	}
	//	return;
	//}
	//else if (check[3] > 26)
	//	return;
	//else
	//{
	//	if (t_input[1] * t_input[5] * t_input[8] * t_input[11] == 0)
	//		return;
	//}


	//if (check[4] < 26)
	//{
	//	if (input[4] == 0)
	//	{
	//		for (int i = 0; i < 12; i++)
	//		{
	//			t_alpha = alpha;
	//			t_input = input;
	//			t_check = check;
	//			if (t_alpha[i] == 0)
	//			{
	//				t_alpha[i] = 1;
	//				t_check[4] += i + 1;
	//				t_input[4] = i + 1;
	//				sol(t_alpha, t_check, t_input);
	//			}
	//		}
	//		return;
	//	}
	//	if (input[6] == 0)
	//	{
	//		for (int i = 0; i < 12; i++)
	//		{
	//			t_alpha = alpha;
	//			t_input = input;
	//			t_check = check;
	//			if (t_alpha[i] == 0)
	//			{
	//				t_alpha[i] = 1;
	//				t_check[4] += i + 1;
	//				t_input[6] = i + 1;
	//				sol(t_alpha, t_check, t_input);
	//			}
	//		}
	//		return;
	//	}
	//	if (input[9] == 0)
	//	{
	//		for (int i = 0; i < 12; i++)
	//		{
	//			t_alpha = alpha;
	//			t_input = input;
	//			t_check = check;
	//			if (t_alpha[i] == 0)
	//			{
	//				t_alpha[i] = 1;
	//				t_check[4] += i + 1;
	//				t_input[9] = i + 1;
	//				sol(t_alpha, t_check, t_input);
	//			}
	//		}
	//		return;
	//	}
	//	if (input[11] == 0)
	//	{
	//		for (int i = 0; i < 12; i++)
	//		{
	//			t_alpha = alpha;
	//			t_input = input;
	//			t_check = check;
	//			if (t_alpha[i] == 0)
	//			{
	//				t_alpha[i] = 1;
	//				t_check[4] += i + 1;
	//				t_input[11] = i + 1;
	//				sol(t_alpha, t_check, t_input);
	//			}
	//		}
	//		return;
	//	}
	//	return;
	//}
	//else if (check[4] > 26)
	//	return;
	//else
	//{
	//	if (t_input[4] * t_input[6] * t_input[9] * t_input[11] == 0)
	//		return;
	//}

	//if (check[5] < 26)
	//{
	//	if (input[1] == 0)
	//	{
	//		for (int i = 0; i < 12; i++)
	//		{
	//			t_alpha = alpha;
	//			t_input = input;
	//			t_check = check;
	//			if (t_alpha[i] == 0)
	//			{
	//				t_alpha[i] = 1;
	//				t_check[5] += i + 1;
	//				t_input[1] = i + 1;
	//				sol(t_alpha, t_check, t_input);
	//			}
	//		}
	//		return;
	//	}
	//	if (input[2] == 0)
	//	{
	//		for (int i = 0; i < 12; i++)
	//		{
	//			t_alpha = alpha;
	//			t_input = input;
	//			t_check = check;
	//			if (t_alpha[i] == 0)
	//			{
	//				t_alpha[i] = 1;
	//				t_check[5] += i + 1;
	//				t_input[2] = i + 1;
	//				sol(t_alpha, t_check, t_input);
	//			}
	//		}
	//		return;
	//	}
	//	if (input[3] == 0)
	//	{
	//		for (int i = 0; i < 12; i++)
	//		{
	//			t_alpha = alpha;
	//			t_input = input;
	//			t_check = check;
	//			if (t_alpha[i] == 0)
	//			{
	//				t_alpha[i] = 1;
	//				t_check[5] += i + 1;
	//				t_input[3] = i + 1;
	//				sol(t_alpha, t_check, t_input);
	//			}
	//		}
	//		return;
	//	}
	//	if (input[4] == 0)
	//	{
	//		for (int i = 0; i < 12; i++)
	//		{
	//			t_alpha = alpha;
	//			t_input = input;
	//			t_check = check;
	//			if (t_alpha[i] == 0)
	//			{
	//				t_alpha[i] = 1;
	//				t_check[5] += i + 1;
	//				t_input[4] = i + 1;
	//				sol(t_alpha, t_check, t_input);
	//			}
	//		}
	//		return;
	//	}
	//	return;

	//}
	//else if (check[5] > 26)
	//	return;
	//else
	//{
	//	if (t_input[1] * t_input[2] * t_input[3] * t_input[4] == 0)
	//		return;
	//}
	////if (check[0] == 26 && check[1] == 26 && check[2] == 26 && check[3] == 26 && check[4] == 26 && check[5] == 26)
	////{
	last[4] = input[0] + 'A' - 1;
	last[11] = input[1] + 'A' - 1;
	last[13] = input[2] + 'A' - 1;
	last[15] = input[3] + 'A' - 1;
	last[17] = input[4] + 'A' - 1;
	last[22] = input[5] + 'A' - 1;
	last[26] = input[6] + 'A' - 1;
	last[31] = input[7] + 'A' - 1;
	last[33] = input[8] + 'A' - 1;
	last[35] = input[9] + 'A' - 1;
	last[37] = input[10] + 'A' - 1;
	last[44] = input[11] + 'A' - 1;
	cout<<last<<endl;
	//	if (t_input[7] * t_input[8] * t_input[9] * t_input[10] == 0)
	//	if (t_input[0] * t_input[2] * t_input[5] * t_input[7] == 0)
//	if (t_input[0] * t_input[3] * t_input[6] * t_input[10] == 0)
//	if (t_input[1] * t_input[5] * t_input[8] * t_input[11] == 0)
//	if (t_input[4] * t_input[6] * t_input[9] * t_input[11] == 0)
// if (t_input[1] * t_input[2] * t_input[3] * t_input[4] == 0) 
	if (input[7] + input[8] + input[9] + input[10] == 26)
	{
		if (input[0] + input[2] + input[5] + input[7] == 26)
		{
			if (input[0] + input[3] + input[6] + input[10] == 26)
			{
				if (input[1] + input[5] + input[8] + input[11] == 26)
				{
					if (input[4] + input[6] + input[9] + input[11] == 26)
					{
						if (input[1] + input[2] + input[3] + input[4] == 26)
							ret.push_back(last);
					}
				}
			}
		}
	}
}

int main()
{
	vector<string> temp(5);
	vector<int>	input(12);
	vector<int>	alpha(13);
	vector<int>	check(6);

	fill(alpha.begin(), alpha.end(), 0);
	fill(check.begin(), check.end(), 0);
	for (int i = 0; i < 5; i++)
	{
		cin>>temp[i];
		for (int j = 0; j < 9; j++)
		{
			if (temp[i][j] >= 'A' && temp[i][j] <= 'L')
			{
				alpha[temp[i][j] - 'A' + 1] = 1;
			}
		}
	}
	input[0] = temp[0][4] - 'A' + 1;input[1] = temp[1][1] - 'A' + 1;input[2] = temp[1][3] - 'A' + 1;input[3] = temp[1][5] - 'A' + 1;input[4] = temp[1][7] - 'A' + 1;input[5] = temp[2][2] - 'A' + 1;
	input[6] = temp[2][6] - 'A' + 1;input[7] = temp[3][1] - 'A' + 1;input[8] = temp[3][3] - 'A' + 1;input[9] = temp[3][5] - 'A' + 1;input[10] = temp[3][7] - 'A' + 1;input[11] = temp[4][4] - 'A' + 1;
	for (int i = 0; i < 12; i++)
	{
		if (input[i] > 12)
			input[i] = 0;
	}
	alpha[0] = 1;
	sol(alpha, check, input);
	sort(ret.begin(), ret.end());
	//cout<<ret[0]<<endl;
}

// ....1....
// .2.3.4.5.
// ..6...7..
// .8.9.10.11.
// ....12....
