#include <bits/stdc++.h>
using namespace std;

vector <int> e[202];
vector <int> c[202];
int n, dis[202];

struct data {
	int dist, city;
	bool operator < (const data &p) const {
		return dist > p.dist;
	}
};

int dijkstra(int source, int destination)
{
	priority_queue <data> q;

	for(int i = 0; i <= n; i++) dis[i] = 0;
	dis[source] = INT_MAX;

	data u, v;
	u.city = source;
	u.dist = INT_MAX;
	q.push(u);

	while(!q.empty()) {
		u = q.top();
		q.pop();
		int ucost = dis[u.city];

		for(int i = 0; i < e[u.city].size(); i++) {
			v.city = e[u.city][i];
			v.dist = min(ucost, c[u.city][i]);


			if(v.dist > dis[v.city]) {
				dis[v.city] = v.dist;
				q.push(v);
			}
		}
	}
	
	return dis[destination];
}


int main()
{
	int m, cs = 0, p, w;
	string u, v;

	while(scanf("%d%d", &n, &m)) {
		if(!m && !n) break;

		map <string, int> mp;

		p = 1;
		for(int i = 0; i < m; i++) {
			cin >> u >> v >> w;
			if(!mp[u]) mp[u] = p++;
			if(!mp[v]) mp[v] = p++;

			e[mp[u]].push_back(mp[v]);
			e[mp[v]].push_back(mp[u]);
			c[mp[u]].push_back(w);
			c[mp[v]].push_back(w);
		}
		cin >> u >> v;

		printf("Scenario #%d\n%d tons\n\n", ++cs, dijkstra(mp[u], mp[v]));

		for(int i = 0; i <= n; i++) {
			e[i].clear();
			c[i].clear();
		}
	}

	return 0;
}
