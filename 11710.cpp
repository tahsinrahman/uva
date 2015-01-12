#include <bits/stdc++.h>
using namespace std;

int parent[500];

int findset(int n)
{
	if(n != parent[n]) parent[n] = findset(parent[n]);
	return parent[n];
}

int main()
{
	int n, m, c, u, v, ans;
	string a, b;

	while(scanf("%d%d", &n, &m)) {
		getchar();
		if(!m && !n) break;

		map <string, int> mp;

		for(int i = 0; i < n; i++) {
			cin >> a;
			mp[a] = i;
		}

		vector <pair<int, pair<int, int> > > edge(m);

		for(int i = 0; i < m; i++) {
			cin >> a >> b >> c;
			edge[i] = make_pair(c, make_pair(mp[a], mp[b]));
		}
		cin >> a;

		sort(edge.begin(), edge.end());

		for(int i = 0; i <= n; i++) parent[i] = i;

		ans = 0;
		c = 0;
		for(int i = 0; i < m; i++) {
			u = findset(edge[i].second.first);
			v = findset(edge[i].second.second);

			if(u != v) {
				ans += edge[i].first;
				parent[u] = parent[v];
				c++;
				if(c == n-1) break;
			}
		}

		if(c == n-1) printf("%d\n", ans);
		else printf("Impossible\n");

	}

	return 0;
}
