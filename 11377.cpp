#include <bits/stdc++.h>
using namespace std;

vector <int> graph[2010];
int n, air[2010];

struct data {
	int city, dist;
	bool operator < (const data &p) const {
		return dist > p.dist;
	}
};

int dijkstra(int src, int des)
{
	if(src == des) return 0;

	vector <bool> vis(n+1);
	int d[n+1];

	for(int i = 1; i <= n; i++) d[i] = INT_MAX;
	d[src] = air[src];

	data u, v;
	u.city = src;
	u.dist = air[src];

	priority_queue <data> q;
	q.push(u);

	while(!q.empty()) {
		u = q.top();
		q.pop();

		int ucost = d[u.city];
		
		if(u.city == des) return ucost;

		if(vis[u.city]) continue;
		vis[u.city] = 1;

		for(int i = 0; i < graph[u.city].size(); i++) {
			v.city = graph[u.city][i];
			v.dist = ucost + air[v.city];

			if(v.dist < d[v.city]) {
				d[v.city] = v.dist;
				q.push(v);
			}
		}
	}

	if(d[des] == INT_MAX) return -1;
	return d[des];
}


int main()
{
	int t, m, k, u, v, q, cs = 0;

	scanf("%d", &t);

	while(t--) {
		scanf("%d%d%d", &n, &m, &k);

		for(int i = 1; i <= n; i++) air[i] = 1;

		while(k--) {
			scanf("%d", &u);
			air[u] = 0;
		}

		while(m--) {
			scanf("%d%d", &u, &v);
			graph[u].push_back(v);
			graph[v].push_back(u);
		}

		scanf("%d", &q);

		printf("Case %d:\n", ++cs);

		while(q--) {
			scanf("%d%d", &u, &v);
			printf("%d\n", dijkstra(u, v));
		}
		printf("\n");

		for(int i = 1; i <= n; i++) graph[i].clear();
	}

	return 0;
}
