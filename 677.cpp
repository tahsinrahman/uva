#include <bits/stdc++.h>
using namespace std;

int n, m, f;
int path[100], a[100][100], vis[100];

void dfs(int source, int dis)
{
	if(dis == m) {
		f = 0;
		printf("(1");
		for(int i = 1; i <= m; i++) printf(",%d", path[i]);
		printf(")\n");
	}

	for(int i = 1; i <= n; i++) {
		if(!vis[i] && a[source][i]) {
			vis[i] = 1;
			path[dis+1] = i;
			dfs(i, dis+1);
			vis[i] = 0;
		}
	}
}


int main()
{
	int tmp;

	while(scanf("%d%d", &n, &m)) {
		for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) scanf("%d", &a[i][j]);

		f = 1;
		vis[1] = 1;
		dfs(1, 0);

		if(f) printf("no walk of length %d\n", m);

		if(scanf("%d", &tmp) == EOF) break;
		printf("\n");
	}

	return 0;
}