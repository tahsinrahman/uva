#include <bits/stdc++.h>
using namespace std;

int n;
vector <int> e[10000];
int p[10000], d[10000];

void bfs(int source)
{
	for(int i = 0; i <= n; i++) d[i] = INT_MAX;
	
	d[source ] = 0;

	queue <int> q;
	q.push(source);

	while(!q.empty()) {
		int u = q.front();
		q.pop();
		int ucost = d[u];

		for(int i = 0; i < e[u].size(); i++) {
			int v = e[u][i];
			int vcost = 1+d[u];

			if(vcost < d[v]) {
				d[v] = vcost;
				p[v] = u;
				q.push(v);
			}
		}
	}
}

int main()
{
	int t, m, c, u, v, x;
	string a, b;

	scanf("%d", &t);

	while(t--) {
		scanf("%d%d", &n, &m);

		map <string, int> mp;
		map <int, char> cp;

		c = 1;
		for(int i = 0; i < n; i++) {
			cin >> a >> b;
			u = mp[a];
			v = mp[b];

			if(!u) {
				u = c++;
				mp[a] = u;
				cp[u] = a[0];
			}
			if(!v) {
				v = c++;
				mp[b] = v;
				cp[v] = b[0];
			}
		
			e[u].push_back(v);
			e[v].push_back(u);
		}

		n = c;

		while(m--) {
			cin >> a >> b;
			u = mp[a];
			v = mp[b];

			bfs(v);

			p[v] = v;
			int x = u;

			while(x != v) {
				printf("%c", cp[x]);
				x = p[x];
			}
			printf("%c\n", b[0]);
		}

		for(int i = 0; i <= n; i++) e[i].clear();

		if(t) printf("\n");
	}

	return 0;
}
