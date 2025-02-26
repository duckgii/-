#include <iostream>
#include <algorithm>

using namespace std;

int seg[1000010];
int input[250010];
int N, K;
int ret_idx;

int changeNum(int idx, int start, int end, int point, int change)
{
	int mid = (start  + end) / 2;

	if (point < start || point > end)
		return (seg[idx]);
	if (start == end)
	{
		if (start == point)
			seg[idx] += change;
		return (seg[idx]);
	}
	seg[idx] = changeNum(idx * 2, start, mid, point, change) + changeNum(idx * 2 + 1, mid + 1, end, point, change);
	return (seg[idx]);
}

void count_seg(int idx, int start, int end, int count)
{
	int mid = (start + end) / 2;

	if (start == end)
	{
		ret_idx = start;
		return ;
	}
	if (seg[idx * 2] >= count)
		count_seg(idx * 2, start, mid, count);
	else
		count_seg(idx * 2 + 1, mid + 1, end, count - seg[idx * 2]);
}

long sol()
{
	long ret = 0;
	int start, end;

	start = 1;
	end = K;
	for (int i = 0; i < K; i++)
	{
		changeNum(1, 0, 65535, input[i], 1); // 이전 값 1 더하기
	}
	for (int i = 0; i < N - K + 1; i++)
	{

		count_seg(1, 0, 65535, (K + 1) / 2);
		ret += ret_idx;
		changeNum(1, 0, 65535, input[i], -1); // 이전 값 1 빼기
		changeNum(1, 0, 65535, input[i + K], 1); // 이전 값 1 더하기
	}
	return (ret);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>N>>K;
	for (int i = 0; i < N; i++)
	{
		cin>>input[i];
	}
	cout<<sol()<<endl;
}