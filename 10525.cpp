#include <bits/stdc++.h>
using namespace std;

int dis[30][30], timee[30][30];

int main()
{
//	freopen("a.txt", "r", stdin);

	int t, n, m, u, v, w, x, q;

	scanf("%d", &t);

	while(t--) {
		scanf("%d%d", &n, &m);

		for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) if(i != j) dis[i][j] = timee[i][j] = 10000000;

		while(m--) {
			scanf("%d%d%d%d", &u, &v, &x, &w);
			if(x < timee[u][v]) {
				timee[u][v] = x;
				timee[v][u] = x;
				dis[u][v] = w;
				dis[v][u] = w;
			}
			else if(x == timee[u][v]) {
				dis[u][v] = min(w, dis[u][v]);
				dis[v][u] = min(w, dis[v][u]);
			}
		}

		for(int k = 1; k <= n; k++) 
			for(int i  = 1; i <= n; i++) 
				for(int j = 1; j <= n; j++) {
					if(timee[i][k] + timee[j][k] < timee[i][j]) {
						timee[i][j] = timee[i][k] + timee[j][k];
						dis[i][j] = dis[i][k] + dis[k][j];
					}
					else if(timee[i][k] + timee[j][k] == timee[i][j]) dis[i][j] = min(dis[i][j], dis[i][k] + dis[j][k]);
				}
		
		scanf("%d", &q);
		while(q--) {
			scanf("%d%d", &u, &v);
			if(timee[u][v] >= 10000000) printf("No Path.\n");
			else printf("Distance and time to reach destination is %d & %d.\n", dis[u][v], timee[u][v]);
		}
		if(t) printf("\n");
	}

	return 0;
}
