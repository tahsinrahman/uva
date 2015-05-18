#include <bits/stdc++.h>
using namespace std;

int n;
map < pair <int, int> , int> dp;
vector < pair < pair <int, int>, int> > a;

int f(int i, int x, int y) {
	if(i == n) return 0;

	pair <int, int> tmp;
	tmp = make_pair(x, y);
	if(dp[tmp]) return dp[tmp];
	
	int p = 0, q = 0;
	if(a[i].first.first > x && a[i].first.second > y) p = a[i].second + f(i+1, a[i].first.first, a[i].first.second);
	q = f(i+1, x, y);

	return dp[tmp] = max(p, q);
}

int main() {
	int u, v, w, cs = 0;
	while(scanf("%d", &n) && n) {
		for(int i = 0; i < n; ++i) {
			scanf("%d%d%d", &u, &v, &w);
			a.push_back(make_pair(make_pair(min(u, v) , max(u, v)), w));
			a.push_back(make_pair(make_pair(min(w, v) , max(w, v)), u));
			a.push_back(make_pair(make_pair(min(u, w) , max(u, w)), v));
		}
		sort(a.begin(), a.end());

		n = a.size();
		printf("Case %d: maximum height = %d\n", ++cs, f(0, 0, 0));

		a.clear();
		dp.clear();
	}

	return 0;
}
