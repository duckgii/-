#include <iostream>

using namespace std;

long long seg[4000010];
long long input[1000010];
long long N, M, K;

long long init_seg(long long idx, long long idx_s, long long idx_e)
{
	long long mid = (idx_s + idx_e) / 2;

	if (idx_s == idx_e)
	{
		seg[idx] = input[idx_s];
		return (seg[idx]);
	}
	seg[idx] = init_seg(idx * 2, idx_s, mid) + init_seg(idx * 2 + 1, mid + 1, idx_e);
	return (seg[idx]);
}

long long change_seg(long long idx, long long start, long long end, long long ch_idx, long long ch_num)
{
	long long mid = (start + end) / 2;

	if (start <= ch_idx && ch_idx <= end)
	{
		seg[idx] -= input[ch_idx];
		seg[idx] += ch_num;
	}
	if (start > ch_idx || ch_idx > end)
		return (seg[idx]);
	if (start == end)
		return (seg[idx]);
	seg[idx] = change_seg(idx * 2, start, mid, ch_idx, ch_num) + change_seg(idx * 2 + 1, mid + 1, end, ch_idx, ch_num);
	return (seg[idx]);
}

void change()
{
	long long a, b;

	cin>>a>>b;
	change_seg(1, 1, N, a, b);
	input[a] = b;
}

long long seg_sum(long long idx, long long start, long long end, long long idx_s, long long idx_e)
{
	long long mid = (idx_s + idx_e) / 2;

	if (end < idx_s || start > idx_e)
		return (0);
	if (idx_s >= start && end >= idx_e)
		return (seg[idx]);
	return (seg_sum(idx * 2, start, end, idx_s, mid) + seg_sum(idx * 2 + 1, start, end, mid + 1, idx_e));
}

void sum()
{
	long long a, b, ret;
	cin>>a>>b;
	ret = seg_sum(1, a, b, 1, N);
	cout<<ret<<'\n';
}

int  main()
{
	cin>>N>>M>>K;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	for (long long i = 0; i < N; i++)
	{
		cin>>input[i + 1];
	}
	init_seg(1, 1, N);
	for (long long i = 0; i < M + K; i++)
	{
		long long cmd;

		cin>>cmd;
		if (cmd == 1)
			change();
		else
			sum();
	}
	return (0);
}
