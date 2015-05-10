#include <bits/stdc++.h>
using namespace std;

int n, flag, vis[1000001];
vector <int> order, edge[1000001];

void DFS(int u) {
	if(flag) return;

	vis[u] = 1;
	for(int i = 0, s = edge[u].size(); i < s; ++i) {
		if(!vis[edge[u][i]]) DFS(edge[u][i]);
		else if(vis[edge[u][i]] == 1) flag = 1;
	}
	vis[u] = 2;
	order.push_back(u);
}

void topsort() {
	flag = 0;
	for(int i = 1; i <= n && !flag; ++i) if(!vis[i]) DFS(i);
	
	if(!flag) for(int i = order.size()-1; i >= 0; --i) printf("%d\n", order[i]);
	else printf("IMPOSSIBLE\n");
}

int main() {
//	freopen("a.txt", "r", stdin);

	int m, u, v;

	while(scanf("%d%d", &n, &m)) {
		if(!n && !m) break;

		while(m--) {
			scanf("%d%d", &u, &v);
			edge[u].push_back(v);
		}

		topsort();

		for(int i = 1; i <= n; ++i) {
			edge[i].clear();
			vis[i] = 0;
		}
		order.clear();
	}

	return 0;
}
