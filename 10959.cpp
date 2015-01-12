#include <bits/stdc++.h>
using namespace std;

int dis[10000], n;
vector <int> e[10000];

void bfs()
{
	for(int i = 1; i < n; i++) dis[i] = INT_MAX;
	dis[0] = 0;

	queue <int> q;
	q.push(0);

	while(!q.empty()) {
		int u = q.front();
		q.pop();
		int ucost = dis[u];

		for(int i = 0; i < e[u].size(); i++) {
			int v = e[u][i];

			if(1+ucost < dis[v]) {
				dis[v] = 1+ucost;
				q.push(v);
			}
		}
	}
}

int main()
{
	int t, m, u, v;

	scanf("%d", &t);

	while(t--) {
		scanf("%d%d", &n, &m);

		while(m--) {
			scanf("%d%d", &u, &v);
			e[u].push_back(v);
			e[v].push_back(u);
		}

		bfs();

		for(int i = 1; i < n; i++) printf("%d\n", dis[i]);
		if(t) printf("\n");

		for(int i = 0; i < n; i++) e[i].clear();
	}

	return 0;
}
