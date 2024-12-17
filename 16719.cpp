#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int		order[100];
int		print[100];

void	recur(int start_idx, int end_idx, int *count)
{
	int min_idx;
	int min = 1000;
	if (start_idx > end_idx)
		return;
	for (int i = start_idx; i <= end_idx; i++)
	{
		if (order[i] < min)
		{
			min = order[i];
			min_idx = i;
		}
	}
	print[min_idx] = *count;
	(*count)++;
	recur(min_idx + 1, end_idx, count);
	recur(start_idx, min_idx - 1, count);
}

int main()
{
	string	input;
	int		count = 1;

	cin>>input;

	while (count <= input.length())
	{
		int min = 1000;
		int min_idx;

		for (int i = 0; i < input.length(); i++)
		{
			if (input[i] < min && order[i] == 0)
			{
				min = input[i];
				min_idx = i;
			}
		}
		order[min_idx] = count++;
	}
	count = 1;
	recur(0, input.length() - 1, &count);
	for (int i = 1; i <= input.length(); i++)
	{
		for (int j = 0; j < input.length(); j++)
		{
			if (print[j] <= i)
				cout<<input[j];
		}
		cout<<endl;
	}
	return (0);
}