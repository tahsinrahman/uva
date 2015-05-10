#include <bits/stdc++.h>
using namespace std;

int n, cs, vis[101], deg[101];
vector <int> order, edge[101];
string a[101];
map <string, int> mp;

struct data {
	int u;
	bool operator < (const data &p) const {
		return u > p.u;
	}
};


void BFS() {
	priority_queue  <data> q;

	data u, v;
	for(int i = 0; i < n; ++i) if(!deg[i]) { u.u = i; q.push(u); }

	while(!q.empty()) {
		int u = q.top().u;
		q.pop();

		order.push_back(u);

		for(int i = 0, s = edge[u].size(); i < s; ++i) {
			v.u = edge[u][i];
			--deg[v.u];
			if(!deg[v.u]) q.push(v);
		}
	}
}


void topsort() {
	BFS();

	printf("Case #%d: Dilbert should drink beverages in this order:", ++cs);
	for(int i = 0, s = order.size(); i < s; ++i) cout << ' ' << a[order[i]];
	printf(".\n\n");
}

int main() {
//	freopen("a.txt", "r", stdin);

	int m;
	string u, v;

	while(scanf("%d", &n) == 1) {
		for(int i = 0; i < n; ++i) {
			cin >> a[i];
			mp[a[i]] = i;
		}

		scanf("%d", &m);
		
		while(m--) {
			cin >> u >> v;
			edge[mp[u]].push_back(mp[v]);
			++deg[mp[v]];
		}

		topsort();

		for(int i = 0; i < n; ++i) {
			edge[i].clear();
			vis[i] = 0;
			deg[i] = 0;
		}
		order.clear();
		mp.clear();
	}

	return 0;
}
