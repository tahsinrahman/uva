#include <bits/stdc++.h>
using namespace std;

int n, vis[202], color[202];
vector <int> edge[202];

int bfs(int src)
{
	if(vis[src]) return 0;

	color[src] = 1;
	vis[src] = 1;
	int x = 0, y = 0;

	queue <int> q;
	q.push(src);
	int f = 0;

	while(!q.empty()) {
		int u = q.front();
		q.pop();

		if(color[u]) x++;
		else y++;

		for(int i = 0; i < edge[u].size(); i++) {
			int v = edge[u][i];
			if(color[v] == color[u]) f = 1;
			color[v] = 1-color[u];

			if(!vis[v]) {
				vis[v] = 1;
				q.push(v);
			}
		}
	}
	if(f) return 0;
	return max(x, y);
}


int main()
{
//	freopen("a.txt", "r", stdin);

	int t, m, p;

	scanf("%d", &t);

	while(t--) {
		scanf("%d", &n);
		for(int i = 1; i <= n; i++) {
			scanf("%d", &p);
			for(int j = 0; j < p; j++) {
				scanf("%d", &m);
				if(m > n) continue;
				edge[i].push_back(m);
				edge[m].push_back(i);
			}
		}
		memset(vis, 0, sizeof(vis));
		memset(color, -1, sizeof(color));

		int ans = 0;

		for(int i = 1; i <= n; i++) ans += bfs(i);

		printf("%d\n", ans);

		for(int i = 1; i <= n; i++) edge[i].clear();
	}
	
	return 0;
}
