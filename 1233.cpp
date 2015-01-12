#include <bits/stdc++.h>
using namespace std;

int dis[503][503];

int main()
{
	int t, u, v, p, n, c;

//	freopen("a.txt", "r", stdin);

	scanf("%d", &t);

	while(t--) {
		scanf("%d%d", &c, &p);

		for(int i = 0; i <= p; i++) 
			for(int j = 0; j <= p; j++) 
				if(i != j) dis[i][j] = 100000000;


		scanf("%d", &n);

		while(n--) {
			scanf("%d", &u);
			dis[0][u] = 0;
		}

		for(int i = 1; i <= p; i++) {
			scanf("%d", &n);

			while(n--) {
				scanf("%d%d", &u, &v);
				dis[i][v] = min(dis[i][v], u);
			}
		}

		dis[0][0] = 100000000;
		for(int k = 0; k <= p; k++) 
			for(int i = 0; i <= p; i++) 
				for(int j = 0; j <= p; j++)
					dis[i][j] = min(dis[i][j], dis[i][k]+dis[k][j]);

		if((c-1)%(dis[0][0]-1)) printf("%d\n", (c-1)/(dis[0][0]-1));
		else printf("%d\n", (c-2)/(dis[0][0]-1));

	}
	scanf("%d", &n);

	return 0;
}
