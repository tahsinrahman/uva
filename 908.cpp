//7.12.2014, 5.54pm

#include <bits/stdc++.h>
using namespace std;

int parent[1000010];

int findset(int n)
{
	if(n != parent[n]) parent[n] = findset(parent[n]);
	return parent[n];
}

int main()
{
	int f, n, ans, i, a, b, c, m, k, u, v;

	f = 0;
	while(scanf("%d", &n) == 1) {
		if(f) printf("\n");

		ans = 0;
		for(int i = 1; i < n; i++) {
			scanf("%d%d%d", &a, &b, &c);
			ans += c;
		}
		printf("%d\n", ans);

		vector <pair <int, pair<int, int> > > edge;
		scanf("%d", &m);

		for(int i = 0; i < m; i++) {
			scanf("%d%d%d", &a, &b, &c);
			edge.push_back(make_pair(c, make_pair(a, b)));
		}

		scanf("%d", &k);
		for(int i = 0; i < k; i++) {
			scanf("%d%d%d", &a, &b, &c);
			edge.push_back(make_pair(c, make_pair(a, b)));
		}

		sort(edge.begin(), edge.end());

		for(int i = 1; i <= n; i++) parent[i] = i;

		ans = 0;
		for(int i = 0; i < m+k; i++) {
			u = findset(edge[i].second.first);
			v = findset(edge[i].second.second);

			if(u != v) {
				ans += edge[i].first;
				parent[u] = parent[v];
			}
		}
		printf("%d\n", ans);

		f = 1;
	}

	return 0;
}
