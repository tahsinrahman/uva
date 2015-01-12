#include <bits/stdc++.h>
using namespace std;

int p[50000010];

int f(int n)
{
	if(n != p[n]) p[n] = f(p[n]);
	return p[n];
}

int main()
{
	int t, n, r, c, cs = 0, u, v;
	
	scanf("%d", &t);

	while(t--) {
		scanf("%d%d", &n, &r);
		int x[n], y[n];

		for(int i = 0; i < n; i++) scanf("%d%d", &x[i], &y[i]);

		vector <pair<double, pair<int, int> > > e( (n*(n-1))>>1);

		c = 0;
		for(int i = 0; i < n; i++) {
			for(int j = i+1; j < n; j++) {
				double d = sqrt( (x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]) );
				e[c++] = make_pair(d, make_pair(i, j));
			}
		}

		sort(e.begin(), e.end());

		for(int i = 0; i <= c; i++) p[i] = i;

		double road = 0;
		double rail = 0;
		int city = 1;
		for(int i = 0; i < c; i++) {
			u = f(e[i].second.first);
			v = f(e[i].second.second);

			if(u != v) {
				if(e[i].first <= r) road += e[i].first;
				else {
					rail += e[i].first;
					city++;
				}
				p[u] = p[v];
			}
		}
		printf("Case #%d: %d %d %d\n", ++cs, city, (int) (road+.5), (int) (rail+.5));
	}

	return 0;
}
