#include <bits/stdc++.h>
using namespace std;

vector <int> edge[30], cost[30];
int n, parent[30], ans;

struct data {
	int city, dist;
	bool operator < (const data &p) const {
		return dist > p.dist;
	}
};


void dijkstra(int src, int des)
{
	vector <bool> vis(n+1);
	vector <int> d(n+1, INT_MAX);

	d[src] = 0;

	data u, v;
	u.city = src;
	u.dist = 0;

	priority_queue <data> q;
	q.push(u);

	while(!q.empty()) {
		u = q.top();
		q.pop();

		int ucost = d[u.city];

		if(u.city == des) {
			ans = ucost;
			return;
		}

		if(vis[u.city]) continue;
		vis[u.city] = 1;

		for(int i = 0; i < edge[u.city].size(); i++) {
			v.city = edge[u.city][i];
			v.dist = ucost + cost[u.city][i];

			if(v.dist < d[v.city]) {
				d[v.city] = v.dist;
				parent[v.city] = u.city;
				q.push(v);
			}
		}
	}
}

int main()
{
	int m, u, v, cs = 0;

//	freopen("a.txt", "r", stdin);

	while(scanf("%d", &n) && n) {
		for(int i = 1; i <= n; i++) {
			scanf("%d", &m);

			while(m--) {
				scanf("%d%d", &u, &v);
				edge[u].push_back(i);
				cost[u].push_back(v);
			}
		}

		scanf("%d%d", &u, &v);

		printf("Case %d: Path = ", ++cs);

		dijkstra(v, u);
		parent[v] = v;
		while(u != v) {
			printf("%d ", u);
			u = parent[u];
		}
		printf("%d", v);

		printf("; %d second delay\n", ans);

		for(int i = 1; i <= n; i++) {
			edge[i].clear();
			cost[i].clear();
		}
	}

	return 0;
}
