#include <bits/stdc++.h>
using namespace std;

int vis[10001];
vector <int> edge[10001];

void DFS(int u) {
	vis[u] = 1;
	for(int i = 0, s = edge[u].size(); i < s; ++i) if(!vis[edge[u][i]]) DFS(edge[u][i]);
}

int main() {
	int t, n, m, l, u, v;

	scanf("%d", &t);

	while(t--) {
		scanf("%d%d%d", &n, &m, &l);

		while(m--) {
			scanf("%d%d", &u, &v);
			edge[u].push_back(v);
		}

		while(l--) {
			scanf("%d", &u);
			if(!vis[u]) DFS(u);
		}

		int cnt = 0;
		for(int i = 1; i <= n; ++i) cnt += vis[i];

		printf("%d\n", cnt);

		for(int i = 1; i <= n; ++i) {
			edge[i].clear();
			vis[i] = 0;
		}
	}

	return 0;
}
