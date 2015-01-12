#include <bits/stdc++.h>
using namespace std;

int p[1000010];

int f(int n)
{
	if(n != p[n]) p[n] = f(p[n]);
	return p[n];
}


int main()
{
	int n, m, u, v, w, ans;

	while(scanf("%d%d", &n, &m)) {
		if(!m && !n) break;

		vector <pair<int, pair<int, int> > > e(m);

		for(int i = 0; i < m; i++) {
			scanf("%d%d%d", &u, &v, &w);
			e[i] = make_pair(w, make_pair(u, v));
		}

		sort(e.begin(), e.end());

		for(int i = 0; i <= n; i++) p[i] = i;

		ans = 0;
		w = 0;
		for(int i = 0; i < m; i++) {
			u = f(e[i].second.first);
			v = f(e[i].second.second);
			if(u != v) {
				ans = max(ans, e[i].first);
				p[u] = p[v];
				w++;
				if(w == n-1) break;
			}
		}
		if(w == n-1) printf("%d\n", ans);
		else printf("IMPOSSIBLE\n");
	}

	return 0;
}
