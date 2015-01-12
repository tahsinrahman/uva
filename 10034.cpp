#include <bits/stdc++.h>
using namespace std;

int parent[102];

int findset(int n)
{
	if(n != parent[n]) parent[n] = findset(parent[n]);
	return parent[n];
}

int main()
{
	int t, n, c, u, v;
	double ans, d;

	scanf("%d", &t);

	while(t--) {
		scanf("%d", &n);
		double x[n], y[n];

		for(int i = 0; i < n; i++) scanf("%lf%lf", &x[i], &y[i]);

		vector <pair <double, pair <int, int> > > edge((n*(n-1))>>1);

		c = 0;
		for(int i = 0; i < n; i++) {
			for(int j = i+1; j < n; j++) {
				d = sqrt( (x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]) ); 
				edge[c++] = make_pair(d, make_pair(i, j));
			}
		}

		sort(edge.begin(), edge.end());

		for(int i = 0; i <= n; i++) parent[i] = i;

		ans = 0;
		for(int i = 0; i < c; i++) {
			u = findset(edge[i].second.first);
			v = findset(edge[i].second.second);

			if(u != v) {
				ans += edge[i].first;
				parent[u] = parent[v];
			}
		}
		printf("%.2lf\n", ans);

		if(t) printf("\n");
	}

	return 0;
}
