#include <bits/stdc++.h>
using namespace std;

int n, c, dis[255], edge[255][255];
vector <int> service;

struct data {
	int city, dist;
	bool operator < (const data &p) const {
		return dist > p.dist;
	}
};

int dijkstra(int source, int des)
{
	for(int i = 0; i < n; i++) dis[i] = INT_MAX;
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

		if(u.city == des) return ucost;

		if(u.city < c) {
			service.push_back(u.city);
			continue;
		}

		for(int i = 0; i < n; i++) {
			if(edge[u.city][i] == -1) continue;

			v.city = i;
			v.dist = ucost + edge[u.city][i];

			if(v.dist < dis[v.city]) {
				dis[v.city] = v.dist;
				q.push(v);
			}
		}
	}
	return dis[des];
}

int main()
{
	int m, k, u, v, w, ans;

	while(scanf("%d%d%d%d", &n, &m, &c, &k)) {
		if(!n && !m && !c && !k) break;

		int dp[c];

		for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) edge[i][j] = -1;

		while(m--) {
			scanf("%d%d%d", &u, &v, &w);
			edge[u][v] = w;
			edge[v][u] = w;
		}


		u = c-1;
		dp[u] = 0;
		u--;
		while(u >= 0) {
			dp[u] = dp[u+1] + edge[u][u+1];
			u--;
		}

		ans = dijkstra(k, c-1);
		for(int i = 0; i < service.size(); i++) {
			ans = min(ans, dp[service[i]] + dis[service[i]]);
		}
		printf("%d\n", ans);



		service.clear();
	}

	return 0;
}
