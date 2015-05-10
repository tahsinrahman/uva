#include <bits/stdc++.h>
using namespace std; 

int vis[100];
vector <int> comp, order, rev[100], edge[100];

void DFS2(int u) {
	vis[u] = 0;
	for(int i = 0; i < rev[u].size(); ++i) if(vis[rev[u][i]]) DFS2(rev[u][i]);
	comp.push_back(u);
}

void DFS1(int u) {
	vis[u] = 1;
	for(int i = 0; i < edge[u].size(); ++i) if(!vis[edge[u][i]]) DFS1(edge[u][i]);
	order.push_back(u);
}

int main() {
	int n, m, cs = 0;
	string u, v;

	while(scanf("%d %d", &n, &m)) {
		if(!n && !m) break;

		map <string, int> mp;
		map <int, string> mp1;

		int tmp = 1;
		while(m--) {
			cin >> u >> v;
			if(!mp[u]) { mp[u] = tmp; mp1[tmp] = u; ++tmp; }
			if(!mp[v]) { mp[v] = tmp; mp1[tmp] = v; ++tmp; }
			edge[mp[u]].push_back(mp[v]);
			rev[mp[v]].push_back(mp[u]);
		}

		memset(vis, 0, sizeof(vis));
		for(int i = 1; i <= n; ++i) if(!vis[i]) DFS1(i);

		if(cs) printf("\n");
		printf("Calling circles for data set %d:\n", ++cs);

		for(int i = 0; i < n; ++i) {
			tmp = order[n-1-i];
			if(vis[tmp]) {
				DFS2(tmp);

				cout << mp1[comp[0]];
				for(int j = 1; j < comp.size(); ++j) cout << ", " << mp1[comp[j]];
				cout << endl;

				comp.clear();
			}
		}

		order.clear();
		for(int i = 0; i <= n; ++i) { edge[i].clear(), rev[i].clear(); }
	}

	return 0;
}
