#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int T, n;

	cin>>T;
	while (T--)
	{
		int dp[2][100001];
		int input[2][100001];
		int ret = 0;

		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 100001; j++)
			{
				dp[i][j] = 0;
				input[i][j] = 0;
			}
		}
		cin>>n;
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin>>input[i][j];
			}
		}
		dp[0][0] = input[0][0];
		dp[1][0] = input[1][0];
		for (int j = 1; j < n; j++)
		{
			for (int i = 0; i < 2; i++)
			{
				if (i == 0)
				{
					if (j > 1)
						dp[i][j] = max(dp[i + 1][j - 1], max(dp[i + 1][j - 2], dp[i][j - 2])) + input[i][j];
					else
						dp[i][j] = dp[i + 1][j - 1] + input[i][j];
				}
				else
				{
					if (j > 1)
						dp[i][j] = max(dp[i - 1][j - 1], max(dp[i - 1][j - 2], dp[i][j - 2])) + input[i][j];
					else
						dp[i][j] = dp[i - 1][j - 1] + input[i][j];
				}
			}
		}
		ret = max(dp[0][n - 1], dp[1][n - 1]);
		cout<<ret<<endl;
	}
	return (0);
}