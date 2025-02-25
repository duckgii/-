#include <iostream>

using namespace std;

long long init[1000010];
long long seg[4000010];
long long lazy[4000010];
long long N, M, K;

long long update_lazy(long long idx, long long add_start, long long add_end, long long start, long long end, long long add_num)
{
	long long mid = (start + end) / 2;
	long long add;
	if (add_start > end || add_end < start)
		return (0);
	if (start >= add_start && end <= add_end)
	{
		lazy[idx] += add_num;
		return (add_num * (end - start + 1));
	}
	add = update_lazy(idx * 2, add_start, add_end, start, mid, add_num) + update_lazy(idx * 2 + 1, add_start, add_end, mid + 1, end, add_num);
	seg[idx] += add;
	return (add);
}

void modify()
{
	long long add_start, add_end, add_num;

	cin>>add_start>>add_end>>add_num;
	update_lazy(1, add_start, add_end, 1, N, add_num);
}

long long sum_lazy(long long idx, long long s_idx, long long e_idx, long long start, long long end)
{
	long long mid = (start + end) / 2;

	if (lazy[idx] != 0)
	{
		if (idx * 2 > 4000010)
		{
			seg[idx] += lazy[idx];
			lazy[idx] = 0;
		}
		else
		{
			seg[idx] += lazy[idx] * (end - start + 1);
			lazy[idx * 2] += lazy[idx];
			lazy[idx * 2 + 1] += lazy[idx];
			lazy[idx] = 0;
		}
	}
	if (s_idx > end || e_idx < start)
		return (0);
	if (start >= s_idx && end <= e_idx)
	{
		//cout<<"idx : "<<idx<<endl;
		return (seg[idx]);
	}
	return (sum_lazy(idx * 2, s_idx, e_idx, start, mid) + sum_lazy(idx * 2 + 1, s_idx, e_idx, mid + 1, end));
	//seg[idx] = sum_lazy(idx * 2, s_idx, e_idx, start, mid) + sum_lazy(idx * 2 + 1, s_idx, e_idx, mid + 1, end) ;
	//return (seg[idx]);
	//-> lazy ㅅㅔ그먼트로 내려가면서 알아서 부모의 노드는 업데이트 되므로 한번 더 초기화할 이유가 없다.
}

void	sum()
{
	long long s_idx, e_idx, ret;

	cin>>s_idx>>e_idx;
	ret = sum_lazy(1, s_idx, e_idx, 1, N);
	cout<<ret<<'\n';
}

long long init_seg(long long idx, long long start, long long end, long long ch_start, long long ch_end)
{
	long long mid = (ch_start + ch_end) / 2;

	if (ch_start == ch_end)
	{
		seg[idx] = init[ch_start];
		//cout<<seg[idx]<<endl;
		return (seg[idx]);
	}
	seg[idx] = init_seg(idx * 2, start, end, ch_start, mid) + init_seg(idx * 2 + 1, start, end, mid + 1, ch_end);
	//cout<<seg[idx]<<endl;
	return (seg[idx]);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>N>>M>>K;
	for (long long i = 0; i < N; i++) {cin>>init[i + 1];}
	init_seg(1, 1, N, 1, N);
	for (long long i = 0; i < M + K; i++)
	{
		long long cmd;

		cin>>cmd;
		if (cmd == 1)
			modify();
		else
			sum();
	}

}