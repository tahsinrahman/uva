#include <bits/stdc++.h>
using namespace std;

vector <int> e[1000];
int n, d[1000], p[1000];

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

		for(int i = 0; i < e[u.city].size(); i++) {
			v.city = e[u.city][i];
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
	string a, b;
	int c, u, v, m, f = 0;

	while(scanf("%d", &n) == 1) {
		if(f) printf("\n");
		f = 1;

		map <string, int> mp;
		map <int, string> mp1;

		c = 1;
		for(int i = 0; i < n; i++) {
			cin >> a >> b;
			if(!mp[a]) mp[a] = c++;
			if(!mp[b]) mp[b] = c++;
			u = mp[a];
			v = mp[b];
			mp1[u] = a;
			mp1[v] = b;

			e[u].push_back(v);
			e[v].push_back(u);
		}
		n = c;

		cin >> a >> b;
		u = mp[a];
		v = mp[b];

		if(!u || !v) {
			printf("No route\n");
			continue;
		}

		dijkstra(v, u);

		
		if(d[u] == INT_MAX) {
			printf("No route\n");
			continue;
		}

		m = u;
		p[v] = v;

		while(m != v) {
			cout << mp1[m] << ' ' <<  mp1[p[m]] << endl;
			m = p[m];
		}

		for(int i = 0; i <= n; i++) e[i].clear();
	}
		
	return 0;
}
