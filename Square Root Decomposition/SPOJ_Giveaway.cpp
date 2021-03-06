//https://www.spoj.com/problems/GIVEAWAY/
#include<bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define int long long
#define MOD 1000000007
#define N 100005

int b = 0;
vector<vector<int>> block;
vector<int> arr;

void update(int index, int val)
{
	auto it = lower_bound(block[index / b].begin(), block[index / b].end(), arr[index]);
	block[index / b].erase(it);
	arr[index] = val;
	auto ip = upper_bound(block[index / b].begin(), block[index / b].end(), val);
	block[index / b].insert(ip, val);
}

int query(int l, int r, int c)
{
	int ans = 0;
	while (l % b != 0 && l <= r)
	{
		if (arr[l] >= c)
			ans++;
		l++;
	}
	while (l + b <= r)
	{
		auto it = lower_bound(block[l / b].begin(), block[l / b].end(), c);
		int num = block[l / b].end() - it;
		ans += num;
		l += b;
	}
	while (l <= r)
	{
		if (arr[l] >= c)
			ans++;
		l++;
	}
	return ans;
}

int32_t main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	fastio();
	int n;
	cin >> n;
	b = sqrt(n);
	arr.resize(n, 0);
	int sz = (n + b + 1) / b;
	block.resize(sz);
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		arr[i] = a;
		block[i / b].push_back(a);
	}
	for (int i = 0; i < sz; i++)
		sort(block[i].begin(), block[i].end());

	int q;
	cin >> q;
	while (q--)
	{
		int temp;
		cin >> temp;
		if (temp == 0)
		{
			//query
			int l, r, c;
			cin >> l >> r >> c;
			l--;
			r--;
			cout << query(l, r, c) << endl;
		}
		else
		{
			//update
			int index, val;
			cin >> index >> val;
			index--;
			update(index, val);
		}
	}

}
