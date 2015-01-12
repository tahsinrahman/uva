#include <bits/stdc++.h>
using namespace std;

vector <int> e[102];
vector <int> c[102];
int n, d[102];

struct data {
	int city, dist;
	bool operator < (const data &p) const {
		return dist < p.dist;
	}
};

int dijkstra(int source, int destination)
{

	for(int i = 0; i <= n; i++) d[i] = 0;

	d[source] = INT_MAX;
	
	data u, v;
	u.city = source;
	u.dist = INT_MAX;

	priority_queue<data> q;
	q.push(u);

	while(!q.empty()) {
		u = q.top();
		q.pop();
		int ucost = d[u.city];

		if(u.city == destination) return d[destination];

		for(int i = 0; i < e[u.city].size(); i++) {
			v.city = e[u.city][i];
			v.dist = min(ucost, c[u.city][i]);

			if(v.dist > d[v.city]) {
				d[v.city] = v.dist;
				q.push(v);
			}
		}
	}
	return d[destination];
}

int main()
{
	int m, u, v, w, cs = 0;

	while(scanf("%d%d", &n, &m)) {
		if(!n && !m) break;

		while(m--) {
			scanf("%d%d%d", &u, &v, &w);
			e[u].push_back(v);
			e[v].push_back(u);
			c[u].push_back(w);
			c[v].push_back(w);
		}

		scanf("%d%d%d", &u, &v, &w);

		m = dijkstra(u, v)-1;

		printf("Scenario #%d\nMinimum Number of Trips = %d\n\n", ++cs, (int) (w+m-1)/m);

		for(int i = 0; i <= n; i++) {
			e[i].clear();
			c[i].clear();
		}

	}

	return 0;
}
