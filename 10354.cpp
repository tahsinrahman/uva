#include <bits/stdc++.h>
using namespace std;

int p, bossRoute[103];
vector <int> edge[103], cost[103], parent[103];

struct data {
	int city, dist;
	bool operator < (const data &p) const {
		return dist > p.dist;
	}
};

int dijkstra(int src, int des)
{
	vector <int> dis(p+1, INT_MAX);
	vector <bool> vis(p+1);

	dis[src] = 0;

	data u, v;
	u.city = src;
	u.dist = 0;

	priority_queue <data> q;
	q.push(u);

	while(!q.empty()) {
		u = q.top(); q.pop();

		int ucost = dis[u.city];
		if(bossRoute[u.city]) continue;
		if(u.city == des) return ucost;
		if(vis[u.city]) continue;
		vis[u.city] = 1;

		for(int i = 0; i < edge[u.city].size(); i++) {
			v.city = edge[u.city][i];
			v.dist = ucost + cost[u.city][i];

			if(v.dist < dis[v.city]) {
				dis[v.city] = v.dist;
				parent[v.city].clear();
				parent[v.city].push_back(u.city);
				q.push(v);
			}
			else if(v.dist == dis[v.city]) parent[v.city].push_back(u.city);
		}
	}
	return -1;
}

void removePath(int src)
{
	bossRoute[src] = 1;
	for(int i = 0; i < parent[src].size(); i++) removePath(parent[src][i]);
}



int main()
{
//	freopen("a.txt", "r", stdin);

	int r, bh, o, yh, m, u, v, w, ans;

	while(scanf("%d%d%d%d%d%d", &p, &r, &bh, &o, &yh, &m) == 6) {
		while(r--) {
			scanf("%d%d%d", &u, &v, &w);
			edge[u].push_back(v);
			edge[v].push_back(u);
			cost[u].push_back(w);
			cost[v].push_back(w);
		}

		for(int i = 0; i <= p; i++) bossRoute[i] = 0;

		ans = dijkstra(bh, o);
		removePath(o);

		ans = dijkstra(yh, m);
		if(ans == -1) printf("MISSION IMPOSSIBLE.\n");
		else printf("%d\n", ans);

		for(int i = 0; i <= p; i++) {
			edge[i].clear();
			parent[i].clear();
			cost[i].clear();
		}
	}

	return 0;
}
