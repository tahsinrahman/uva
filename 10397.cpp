#include <bits/stdc++.h>
using namespace std;

int p[800];

int f(int n)
{
	if(n != p[n]) p[n] = f(p[n]);
	return p[n];
}


int main()
{
	int n, m, u, v, w;
	double d, ans;

	while(scanf("%d", &n) == 1) {
		int x[n+1], y[n+1];
		for(int i = 1; i <= n; i++) scanf("%d%d", &x[i], &y[i]);

		vector <pair<double, pair<int, int> > > e;

		for(int i = 1; i <= n; i++) {
			for(int j = i+1; j <= n; j++) {
				d = sqrt( (x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]) );
				e.push_back(make_pair(d, make_pair(i, j)));
			}
		}

		scanf("%d", &m);
		for(int i = 0; i < m; i++) {
			scanf("%d%d", &u, &v);
			e.push_back(make_pair(0, make_pair(u, v)));
		}
				
		sort(e.begin(), e.end());
		
		for(int i = 0; i <= n; i++) p[i] = i;

		ans = 0;
		w = 0;
		for(int i = 0; i < e.size(); i++) {
			u = f(e[i].second.first);
			v = f(e[i].second.second);
			
			if(u != v) {
				ans += e[i].first;
				w++;
				p[u] = p[v];
				if(w == n-1) break;
			}
		}
		printf("%.2lf\n", ans);
	}

	return 0;
}
