#include <bits/stdc++.h>
using namespace std;

vector <int> edge[28];
int dis[28], deg[28], tme[28];

void DFS(int u, int d) {
	for(int i = 0; i < edge[u].size(); ++i) {
		if(d + tme[edge[u][i]] > dis[edge[u][i]]) {
			dis[edge[u][i]] = d + tme[edge[u][i]];
			DFS(edge[u][i], dis[edge[u][i]]);
		}
	}
}

struct data {
	int city, dist;

	bool operator < (const data &p) const {
		return dist < p.dist;
	}
};

void dijkstra(int src) {
	priority_queue <data> q;
	vector <int> vis(28);

	
	data u, v;
	u.city = src;
	u.dist = tme[src];

	q.push(u);

	while(!q.empty()) {
		u = q.top();
		q.pop();

		vis[u.city] = 1;

		for(int i = 0, s = edge[u.city].size(); i < s; ++i) {
			v.city = edge[u.city][i];
			v.dist = u.dist + tme[v.city];

			if(v.dist > dis[v.city]) {
				dis[v.city] = v.dist;
				q.push(v);
			}
		}
	}
}


int main() {
	int t, n;
	char ch;
	string a;

	scanf("%d", &t);
	getchar();
	getchar();

	while(t--) {
		n = 1;

		map <char, int> mp;

		while(getline(cin, a) && !a.empty()) {
			stringstream ss(a);
			ss >> ch;
			if(!mp[ch]) mp[ch] = n++;

			int u = mp[ch];
			ss >> tme[u];

			while(ss >> ch) {
				if(!mp[ch]) mp[ch] = n++;
				int v = mp[ch];
				edge[u].push_back(v);
				++deg[v];
			}
		}
//		for(int i = 1; i <= n; ++i) if(!deg[i]) DFS(i, tme[i]);
		for(int i = 1; i <= n; ++i) if(!deg[i]) dijkstra(i);

		int mx = 0;
		for(int i = 1; i <= n; ++i) mx = max(mx, dis[i]);

		printf("%d\n", mx);
		if(t) printf("\n");

		for(int i = 1; i <= n; ++i) {
			dis[i] = 0;
			edge[i].clear();
			deg[i] = 0;
		}
	}

	return 0;
}
