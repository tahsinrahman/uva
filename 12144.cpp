#include <bits/stdc++.h>
using namespace std;

int n, dis[502], graph[502][502];
vector <int> parent[502];

struct data {
	int city, dist;
	bool operator < (const data &p) const {
		return dist > p.dist;
	}
};

void remove_path(int source)
{
	for(int i = 0; i < parent[source].size(); i++) {
		graph[parent[source][i]][source] = 0;
		remove_path(parent[source][i]);
	}
}

int dijkstra(int source, int destination)
{
	vector <int> vis(n);

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

		if(u.city == destination) return ucost;

		if(vis[u.city]) continue;
		vis[u.city] = 1;

		for(int i = 0; i < n; i++) {
			if(!graph[u.city][i]) continue;

			v.city = i;
			v.dist = ucost + graph[u.city][i];

			if(v.dist <= dis[i]) {
				if(v.dist < dis[i]) {
					dis[i] = v.dist;
					parent[v.city].clear();
					parent[v.city].push_back(u.city);
					q.push(v);
				}
				else parent[v.city].push_back(u.city);
			}
		}
	}
		

	return dis[destination];
}

int main()
{
	int m, u, v, w, mn1, source, destination, mn2;

	while(scanf("%d%d", &n, &m)) {
		if(!n && !m) break;

		scanf("%d%d", &source, &destination);

		for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) graph[i][j] = 0;

		while(m--) {
			scanf("%d%d%d", &u, &v, &w);
			graph[u][v] = w;
		}

		mn1 = dijkstra(source, destination);
		remove_path(destination);

		if(mn1 == INT_MAX) printf("-1\n");
		
		else {
			mn2 = dijkstra(source, destination);
			if(mn2 == INT_MAX) printf("-1\n");
			else printf("%d\n", mn2);
		}
		for(int i = 0; i < n; i++) parent[i].clear();
	}


	return 0;
}
