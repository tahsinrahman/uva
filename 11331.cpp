#include <bits/stdc++.h>
using namespace std;

int b;
int vis[2010], color[2010], dp[2005][1005];
vector <int> edge[2010];
vector <pair <int, int> > a;

int f(int i, int w)
{
	if(i == a.size()) {
		if(w == b) return 1;
		else return 0;
	}

	if(dp[i][w] != -1) return dp[i][w];

	int p = 0, q = 0;

	if(w+a[i].first <= b) p = f(i+1, w+a[i].first);
	if(w+a[i].second <= b) q = f(i+1, w+a[i].second);

	return dp[i][w] = p|q;
}

bool bfs(int source)
{
	vis[source] = 1;
	color[source] = 1;
	int pp = 0, qq = 0;

	queue <int> q;
	q.push(source);

	while(!q.empty()) {
		int u = q.front();
		q.pop();

		if(color[u]) pp++;
		else qq++;

		for(int i = 0; i < edge[u].size(); i++) {
			int v = edge[u][i];

			if(!vis[v]) {
				vis[v] = 1;
				color[v] = 1-color[u];
				q.push(v);
			}
			else if(color[u] == color[v]) return 0;
		}
	}
	a.push_back(make_pair(pp, qq));


	return 1;
}



int main()
{
	int t,  c, n, flag, u, v;

	scanf("%d", &t);

	while(t--) {
		scanf("%d%d%d", &b, &c, &n);

		for(int i = 0; i <= b+c; i++) { edge[i].clear(); vis[i] = 0; }
		a.clear();

		while(n--) {
			scanf("%d%d", &u, &v);
			edge[u].push_back(v);
			edge[v].push_back(u);
		}

		flag = 1;
		for(int i = 1; i <= b+c; i++) if(!vis[i] && flag) flag = bfs(i);
		
		if(!flag) { printf("no\n"); continue; }

		memset(dp, -1, sizeof(dp));

		if(f(0, 0)) printf("yes\n");
		else printf("no\n");
	}

	return 0;
}
