// Author : Chaudhary Hamdan
// 100 Points

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define sg string
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define f(i,x,y,inc)    for(int i = x; i < y; i += inc)
#define ch_ham ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);


int main()
{
	ch_ham

	/*
	#ifndef ONLINE_JUDGE
		freopen("C:\\Users\\KIIT\\input.txt", "r", stdin);
		freopen("C:\\Users\\KIIT\\output.txt", "w", stdout);
	#endif
	*/
	int t; cin >> t;
	while (t--)
	{
		int n, q, m; cin >> n >> q >> m;
		int ar1[n];
		for (int i = 0; i < n; i++)
			cin >> ar1[i];
		int ar2[1000001] = {};
		int ans[m + 1] = {};

		map<pair<int, int>, int>pair_mapp;
		while (q--)
		{
			int l, r;
			cin >> l >> r;
			l--;
			r--;
			if (ar1[l] > m)
				continue;
			else if (ar1[l] <= m && ar1[r] > m)
				ar2[ar1[l]]++, ar2[m + 1]--;
			else if (ar1[r] <= m)
			{
				ar2[ar1[l]]++, ar2[m + 1]--;
				pair_mapp[ {ar1[l], ar1[r]}]++;
			}
		}

		for (auto pm : pair_mapp)
		{
			int ff = pm.first.first, fs = pm.first.second, ss = pm.second;
			ar2[fs + ff] -= ss, ar2[fs + 2 * ff] += ss;
			int ct = fs + 2 * ff;

			while (ct + fs <= m)
			{
				ct += fs;
				ar2[ct] -= ss, ar2[ct + ff] += ss;
				ct += ff;
			}
		}

		for (int i = 1; i <= m; i++)
			ar2[i] += ar2[i - 1];

		int maxx = 0;
		for (int i = 0; i <= m; i++)
			maxx = max(ar2[i], maxx);
		cout << maxx << endl;
	}

	return 0;
}
