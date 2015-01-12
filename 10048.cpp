#include <bits/stdc++.h>
using namespace std;

#define inf 100000

int main()
{
	int n, m, q, u, v, w, cs = 0;

//	while(scanf("%d%d%d", &n, &m, &q)) {
	scanf("%d%d%d", &n, &m, &q);
	while(n || m || q) {
		if(!n && !m && !q) break;

//		int d[n+1][n+1];
//		memset(d, 0, sizeof(d));
		vector < vector <int> > d(n+1, vector <int> (n+1));

		while(m--) {
			scanf("%d%d%d", &u, &v, &w);
			d[u][v] = w;
			d[v][u] = w;
		}

		for(int i = 1; i <= n; i++) 
			for(int j = 1; j <= n; j++) {
				if(i == j) d[i][j] = 0;
				else if(!d[i][j]) d[i][j] = inf;
			}

		for(int k = 1; k <= n; k++) 
			for(int i = 1; i <= n; i++) 
				for(int j = 1; j <= n; j++) 
					d[i][j] = min(d[i][j], max(d[i][k], d[k][j]));

		printf("Case #%d\n", ++cs);
		while(q--) {
			scanf("%d%d", &u, &v);
			if(d[u][v] == inf) printf("no path\n");
			else printf("%d\n", d[u][v]);
		}

		scanf("%d%d%d", &n, &m, &q);
		if(n || m || q) printf("\n");
	}

	return 0;
}
