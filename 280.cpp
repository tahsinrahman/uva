#include <bits/stdc++.h>
using namespace std;

int vis[101];
vector <int> edge[101];

void DFS(int u) {
	vis[u] = 1;
	for(int i = 0; i < edge[u].size(); ++i) if(!vis[edge[u][i]]) DFS(edge[u][i]);
}

int main() {
	int n, m, u, v;
	while(scanf("%d", &n) && n) {

		while(scanf("%d", &u) && u) while(scanf("%d", &v) && v) edge[u].push_back(v);

		scanf("%d", &m);
		while(m--) {
			scanf("%d", &u);
			memset(vis, 0, sizeof(vis));
			
			for(int i = 0; i < edge[u].size(); ++i) if(!vis[edge[u][i]]) DFS(edge[u][i]);

			vector <int> res;
			for(int i = 1; i <= n; ++i) if(!vis[i]) res.push_back(i);

			printf("%d", res.size());
			for(int i = 0, s = res.size(); i < s; ++i) printf(" %d", res[i]);
			printf("\n");
		}

		for(int i = 1; i <= n; ++i) edge[i].clear();
	}

	return 0;
}
