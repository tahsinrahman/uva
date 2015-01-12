#include <bits/stdc++.h>
using namespace std;

int parent[200010];

int findset(int n)
{
	if(n != parent[n]) parent[n] = findset(parent[n]);
	return parent[n];
}

int main()
{
	int n, m, a, b, c, total, ans, u, v;

	while(scanf("%d%d", &n, &m)) {
		if(!n && !m) break;


		vector <pair <int, pair<int, int> > > edge(m);
	
		total = 0;
		for(int i = 0; i < m; i++) {
			scanf("%d%d%d", &a, &b, &c);
			edge[i] = make_pair(c, make_pair(a, b));
			total += c;
		}

		sort(edge.begin(), edge.end());

		for(int i = 0; i <= n; i++) parent[i] = i;

		ans = 0;
		for(int i = 0; i < m; i++) {
			u = findset(edge[i].second.first);
			v = findset(edge[i].second.second);

			if(u != v) {
				ans += edge[i].first;
				parent[u] = parent[v];
			}
		}
		printf("%d\n", total-ans);
	}

	return 0;
}
