#include <bits/stdc++.h>
using namespace std;

int n, dis1[10002], dis2[10002];
vector <int> graph[10002], rev[10002], cost1[10002], cost2[10002];

struct data {
	int city, dist;
	bool operator < (const data &p) const {
		return dist > p.dist;
	}
};

void dijkstra(int source, vector <int> edge[], vector <int> cost[], int dis[])
{
	for(int i = 1; i <= n; i++) dis[i] = INT_MAX;
	dis[source] = 0;

	data u, v;
	u.city = source;
	u.dist = 0;

	priority_queue <data> q;
	q.push(u);

	while(!q.empty()) {
		u = q.top();
		q.pop();

		int ucost = dis[u.city];

		for(int i = 0; i < edge[u.city].size(); i++) {
			v.city = edge[u.city][i];
			v.dist = ucost + cost[u.city][i];

			if(v.dist < dis[v.city]) {
				dis[v.city] = v.dist;
				q.push(v);
			}
		}
	}
}

int main()
{
	int T, m, s, t, p, ans;

	scanf("%d", &T);

	while(T--) {
		scanf("%d%d%d%d%d", &n, &m, &s, &t, &p);
		int u[m], v[m], w[m];

		for(int i = 0; i < m; i++) {
			scanf("%d%d%d", &u[i], &v[i], &w[i]);
			graph[u[i]].push_back(v[i]);
			rev[v[i]].push_back(u[i]);
			cost1[u[i]].push_back(w[i]);
			cost2[v[i]].push_back(w[i]);
		}

		dijkstra(s, graph, cost1, dis1);
		dijkstra(t, rev, cost2, dis2);

		ans = -1;
		for(int i = 0; i < m; i++) {
			if(dis1[u[i]] != INT_MAX && dis2[v[i]] != INT_MAX && dis1[u[i]]+dis2[v[i]]+w[i] <= p) ans = max(ans, w[i]);
		}

		printf("%d\n", ans);

		for(int i = 1; i <= n; i++) {
			graph[i].clear();
			rev[i].clear();
			cost1[i].clear();
			cost2[i].clear();
		}
	}

	return 0;
}
