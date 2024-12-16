#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void	backtracking(vector<int> input, vector<int> print, int count)
{
	count -= 1;
	if (count == -1)
	{
		for (int i = 0; i < static_cast<int>(print.size()); i++)
		{
			cout<<print[i]<<" ";
		}
		cout<<'\n';
		return ;
	}
	for (int i = 0; i < static_cast<int>(input.size()); i++)
	{
		vector<int> tempInput = input;
		vector<int> tempPrint = print;

		tempInput.erase(tempInput.begin() + i);
		tempPrint.push_back(input[i]);
		backtracking(tempInput, tempPrint, count);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M, temp;
	vector<int>	input;
	vector<int>	print;

	cin>>N>>M;
	for (int i = 0; i < N; i++)
	{
		cin>>temp;
		input.push_back(temp);
	}
	sort(input.begin(), input.end());
	backtracking(input, print, M);
	return (0);
}