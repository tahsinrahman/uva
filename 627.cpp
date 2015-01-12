#include <bits/stdc++.h>
using namespace std;

//vector <int> e[302];
int e[302][302];
int d[302], n, p[302];

struct data {
	int city, dist;
	bool operator < (const data &p) const {
		return dist > p.dist;
	}
};


void dijkstra(int source, int des)
{
	for(int i = 0; i <= n; i++) d[i] = INT_MAX;
	d[source] = 0;

	data u, v;
	u.city = source;
	u.dist = 0;

	priority_queue <data> q;
	q.push(u);

	while(!q.empty()) {
		u = q.top();
		q.pop();
		

		if(u.city == des) return;

		int ucost = d[u.city];

		for(int i = 1; i <= n; i++) {
			if(!e[u.city][i]) continue;
			v.city = i;
			v.dist = 1+ucost;

			if(v.dist < d[v.city]) {
				d[v.city] = v.dist;
				p[v.city] = u.city;
				q.push(v);
			}
		}
	}
}


int main()
{
	int u, v, q, m;
	string a;

	while(scanf("%d", &n) == 1) {
		memset(e, 0, sizeof(e));

		for(int i = 0; i < n; i++) {
			scanf("%d", &u);
			cin >> a;

			a[0] = ' ';
			for(int i = 0, l = a.length(); i < l; i++) if(a[i] == ',') a[i] = ' ';
			stringstream ss(a);

			while(ss >> v) e[u][v] = 1;
		}
		
		printf("-----\n");

		scanf("%d", &q);

		while(q--) {
			scanf("%d%d", &u, &v);
			dijkstra(u, v);
			if(d[v] == INT_MAX) {
				printf("connection impossible\n");
				continue;
			}
			vector <int> path;
			p[u] = 0;
			m = v;

			while(m) {
				path.push_back(m);
				m = p[m];
			}
			printf("%d", u);
			for(int i = path.size()-2; i >= 0; i--) printf(" %d", path[i]);
			printf("\n");
		}

	}

		
	return 0;
}
