#include <bits/stdc++.h>
using namespace std;

int p[102];

int f(int n)
{
	if(n != p[n]) p[n] = f(p[n]);
	return p[n];
}


int main()
{
	int t, n, m, u, v, w, ans, mx;

	scanf("%d", &t);
	while(t--) {
		scanf("%d%d", &n, &m);
		
		vector <pair<int, pair<int, int > > > e(m);
		vector <pair<int, pair<int, int > > > mst(n-1);
		vector <int> cheap;

		for(int i = 0; i < m; i++) {
			scanf("%d%d%d", &u, &v, &w);
			e[i] = make_pair(w, make_pair(u, v));
		}

		sort(e.begin(), e.end());
		
		for(int i = 0; i <=n; i++) p[i] = i;

		w = 0;
		ans = 0;
		for(int i = 0; i < m; i++) {
			u = f(e[i].second.first);
			v = f(e[i].second.second);

			if(u != v) {
				ans += e[i].first;
				mst[w++] = e[i];
				if(w == n-1) break;
				p[u] = p[v];
			}
		}
		printf("%d ", ans);

		mx = INT_MAX;
		for(int i = 0; i < mst.size(); i++) {
			for(int j = 0; j <= n; j++) p[j] = j;
			ans = 0;
			w = 0;
			for(int j = 0; j < m; j++) {
				if(mst[i] == e[j]) continue;
				u = f(e[j].second.first);
				v = f(e[j].second.second);

				if(u != v) {
					ans += e[j].first;
					w++;
					if(w == n-1) break;
					p[u] = p[v];
				}
			}
			if(w == n-1) mx = min(mx, ans);
		}

		printf("%d\n", mx);

	}

	return 0;
}
