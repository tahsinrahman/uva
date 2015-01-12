#include <bits/stdc++.h>
using namespace std;

int p[1010];

int f(int n)
{
	if(n != p[n]) p[n] = f(p[n]);
	return p[n];
}


int main()
{
	int n, m, u, v, w, t, ff;

	while(scanf("%d%d", &n, &m)) {
		if(!m && !n) break;

		vector <pair<int, pair<int, int> > > e(m);

		for(int i = 0; i < m; i++) {
			scanf("%d%d%d", &u, &v, &w);
			e[i] = make_pair(w, make_pair(u, v));
		}

		sort(e.begin(), e.end());
		for(int i = 0; i <= n; i++) p[i] = i;

		ff = 0;
		for(int i = 0; i < m; i++) {
			u = f(e[i].second.first);
			v = f(e[i].second.second);

			if(u != v) p[u] = p[v];
			else {
				if(ff) printf(" ");
				printf("%d", e[i].first);
				ff = 1;
			}
		}
		if(ff) printf("\n");
		else printf("forest\n");
	}

	return 0;
}
