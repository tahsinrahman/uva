#include <bits/stdc++.h>
using namespace std;

int n, s, des;
vector <int> e[20010];
vector <int> c[20010];
int d[20010];

struct data {
	int city, dist;
	bool operator < (const data &p) const {
		return dist > p.dist;
	}
};


void dijkstra()
{
	for(int i = 0; i < n; i++) d[i] = INT_MAX;
	d[s] = 0;
	
	data u, v;
	u.city = s;
	u.dist = 0;

	priority_queue <data> q;
	q.push(u);

	while(!q.empty()) {
		u = q.top();
		q.pop();

		if(u.city == des) return;

		int ucost = d[u.city];

		for(int i = 0; i < e[u.city].size(); i++) {
			v.city = e[u.city][i];
			v.dist = ucost + c[u.city][i];

			if(v.dist < d[v.city]) {
				d[v.city] = v.dist;
				q.push(v);
			}
		}
	}
}



int main()
{
	int t, m, u, v, w, cs = 0;

	scanf("%d", &t);

	while(t--) {
		scanf("%d%d%d%d", &n, &m, &s, &des);

		while(m--) {
			scanf("%d%d%d", &u, &v, &w);
			e[u].push_back(v);
			e[v].push_back(u);
			c[u].push_back(w);
			c[v].push_back(w);
		}

		dijkstra();

		printf("Case #%d: ", ++cs);
		if(d[des] == INT_MAX) printf("unreachable\n");
		else printf("%d\n", d[des]);

		for(int i = 0; i < n; i++) {
			e[i].clear();
			c[i].clear();
		}
	}

	return 0;
}
