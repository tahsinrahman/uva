#include <bits/stdc++.h>
using namespace std;

int parent[10010];

int findset(int n)
{
	if(n != parent[n]) parent[n] = findset(parent[n]);
	return parent[n];
}

int main()
{
	int t, n, m, p, a, b, c, ans, u, v, air, cs = 0;

	scanf("%d", &t);

	while(t--) {
		scanf("%d%d%d", &n, &m, &p);

		vector <pair <int, pair<int, int> > > edge(m);
		vector <bool> r(n);

		for(int i = 0; i < m; i++) {
			scanf("%d%d%d", &a, &b, &c);
			edge[i] = make_pair(c, make_pair(a, b));
		}

		sort(edge.begin(), edge.end());

		for(int i = 1; i <= n; i++) parent[i] = i;

		ans = 0;
		air = 0;
		for(int i = 0; i < m; i++) {
			u = findset(edge[i].second.first);
			v = findset(edge[i].second.second);

			if(u != v && edge[i].first < p) {
				ans += edge[i].first;
				parent[u] = parent[v];
				air++;
			}
		}
		air = n-air;

		printf("Case #%d: %d %d\n", ++cs, air*p + ans, air);
	}

	return 0;
}
