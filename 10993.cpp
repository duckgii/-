#include <iostream>
#include <string>
#include <utility>

using namespace std;

int	hori[10];
int	vert[10];

string	recur(pair<int, int> point, pair<int, int>print, int height, int width, int count)
{
	if (count == 0)
		return (" ");
	if (count % 2 == 1)
	{
		if (print.first - point.first < height && (print.first - point.first) == abs(point.second - print.second))
			return ("*");
		if (point.first + height - 1 == print.first && (point.second + width - 1 >= print.second && point.second - width + 1 <= print.second))
			return ("*");
		count--;
		point.first += height - 2; 
		return (recur(point, print, vert[count - 1], hori[count - 1] / 2, count));
	}
	else
	{
		if (((point.first - print.first) < height ) && (point.first - print.first) == abs(point.second - print.second))
			return ("*");
		if (point.first - height + 1 == print.first && (point.second + width - 1 >= print.second && point.second - width + 1 <= print.second))
			return ("*");
		count--;
		point.first -= height - 2; 
		return (recur(point, print, vert[count - 1], hori[count - 1] / 2, count));
	}
}

int main()
{
	int	N = 0;
	pair<int, int>	point;
	pair<int, int>	print;
	string ret;
	cin>>N;
	hori[0] = 1;
	vert[0] = 1;
	for (int i = 1; i < 10; i++)
	{
		hori[i] = hori[i - 1] + 2 * (vert[i - 1] + 1);
		vert[i] = vert[i - 1] + 1 + (hori[i - 1] / 2 + 1);
	}
	if (N % 2 == 0)
		point = make_pair(vert[N - 1], hori[N - 1] / 2 + 1);
	else
		point = make_pair(1, hori[N - 1] / 2 + 1);
	for (int i = 1; i <= vert[N - 1]; i++)
	{
		string	temp;
		int count = 0;
		for (int j = 1; j <= hori[N - 1]; j++)
		{
			print = make_pair(i, j);
			temp += recur(point, print, vert[N - 1], hori[N - 1] / 2, N);
		}
		while (temp.size())
		{
			if (temp[temp.size() - 1 - count] == ' ')
				count++;
			else
				break;
		}
		temp = temp.substr(0, temp.size() - count);
		temp += '\n';
		ret += temp;
	}
	cout<<ret;
}
//hori 1 5 {5 + 2 * (3 + 1)} = 13     hori[i] => hori[i - 1] + 2 * (vert[i - 1] + 1)
//vert 1 3 {3 + 1 + 5 / 2 + 1} = 7    vert[i] => vert[i - 1] + 1 + (hori[i - 1] / 2 + 1)