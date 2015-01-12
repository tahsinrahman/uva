#include <bits/stdc++.h>
using namespace std;

int x[200], y[200], r[200], n;
vector <int> edge[200];

int bfs()
{
	vector <bool> vis(n+4);
	vis[0] = 1;

	queue <int> q;
	q.push(0);

	while(!q.empty()) {
		int u = q.front();
		q.pop();

		if(u == 1) return 1;

		for(int i = 0; i < edge[u].size(); i++) {
			int v = edge[u][i];

			if(!vis[v]) {
				vis[v] = 1;
				q.push(v);
			}
		}
	}
	return 0;
}

int main()
{
//	freopen("a.txt", "r", stdin);

	int k, m;

	while(scanf("%d%d", &k, &m) == 2) {
		scanf("%d%d%d", &x[0], &y[0], &r[0]);
		scanf("%d%d%d", &x[1], &y[1], &r[1]);

		scanf("%d", &n);

		for(int i = 0; i < n; i++) scanf("%d%d%d", &x[i+2], &y[i+2], &r[i+2]);
		n += 2;

		for(int i = 0; i < n; i++) {
			for(int j = i+1; j < n; j++) {
				int d = ( (x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]) );
				if(d <= (k*m+r[i]+r[j])*(k*m+r[i]+r[j])) {
					edge[i].push_back(j);
					edge[j].push_back(i);
				}
			}
		}

		if(bfs()) printf("Larry and Ryan will escape!\n");
		else printf("Larry and Ryan will be eaten to death.\n");

		for(int i = 0; i <= n+3; i++) edge[i].clear();
	}

	return 0;
}
