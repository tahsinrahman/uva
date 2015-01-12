#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, m, u, v, cs = 0;
	int dis[30][30];

//	freopen("a.txt", "r", stdin);

	while(scanf("%d", &n) == 1) {

		memset(dis, 0, sizeof(dis));

		while(n--) {
			scanf("%d", &m);
			dis[1][m] = dis[m][1] = 1;
		}
	
		for(int i = 2; i <= 19; i++) {
			scanf("%d", &n);
			while(n--) {
				scanf("%d", &m);
				dis[i][m] = dis[m][i] = 1;
			}
		}


		for(int i = 1; i <= 20; i++) {
			for(int j = 1; j <= 20; j++) {
				if(i != j && dis[i][j] != 1) dis[i][j] = 100000;
			}
		}

		for(int k = 1; k <= 20; k++) 
			for(int i = 1; i <= 20; i++) 
				for(int j = 1; j <= 20; j++) dis[i][j]= min(dis[i][j], dis[i][k] + dis[k][j]);
		
		scanf("%d", &n);

		printf("Test Set #%d\n", ++cs);
		while(n--) {
			scanf("%d%d", &u, &v);
			printf("%2d to %2d: %d\n", u, v, dis[u][v]);
		}
		printf("\n");
	}

		return 0;
}
