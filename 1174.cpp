#include <bits/stdc++.h>
using namespace std;

int parent[50004];

int findset(int n)
{
	if(n != parent[n]) parent[n] = findset(parent[n]);
	return parent[n];
}

int main()
{
	int t, n, m, c, d, ans, u, v;
	string a, b;

	scanf("%d", &t);
	getchar();

	while(t--) {
		scanf("%d%d", &n, &m);
		getchar();

		map <string, int> mp;
		vector <pair<int, pair<int, int> > > edge(m);

		c = 1;
		for(int i = 0; i < m; i++) {
			cin >> a >> b >> d;
			if(!mp[a]) mp[a] = c++;
			if(!mp[b]) mp[b] = c++;

			edge[i] = make_pair(d, make_pair(mp[a], mp[b]));
		}

		sort(edge.begin(), edge.end());

		for(int i = 1; i <= n; i++) parent[i] = i;

		ans = 0;
		for(int i = 0; i < m; i++) {
			u = findset(edge[i].second.first);
			v = findset(edge[i].second.second);

			if(u != v) {
				ans += edge[i].first;
				parent[u] = parent[v];
			}
		}
		printf("%d\n", ans);

		if(t) printf("\n");
	}

	return 0;
}
