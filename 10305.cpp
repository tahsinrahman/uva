#include <bits/stdc++.h>
using namespace std;

int vis[101];
vector <int> order, edge[101];

void DFS(int u) {
	vis[u] = 1;
	for(int i = 0, s = edge[u].size(); i < s; ++i) if(!vis[edge[u][i]]) DFS(edge[u][i]);
	order.push_back(u);
}

int main() {
//	freopen("a.txt", "r", stdin);

	int n, m, u, v;
	while(scanf("%d%d", &n, &m)) {
		if(!n && !m) break;

		while(m--) {
			scanf("%d%d", &u, &v);
			edge[u].push_back(v);
		}

		for(int i = 1; i <= n; ++i) if(!vis[i]) DFS(i);

		printf("%d", order[order.size()-1]);
		for(int i = order.size()-2; i >= 0; --i) printf(" %d", order[i]);
		printf("\n");


		for(int i = 1; i <= n; ++i) {
			edge[i].clear();
			vis[i] = 0;
		}
		order.clear();
	}

	return 0;
}
