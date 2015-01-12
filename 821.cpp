#include <bits/stdc++.h>
using namespace std;

int dis[102][102];

int main()
{
	int a, b, n, sum, cs = 0;

	freopen("a.txt", "r", stdin);

	while(scanf("%d%d", &a, &b)) {
		if(!a && !b) break;

		for(int i = 1; i <= 100; i++) for(int j = 1; j <= 100; j++) if(i != j) dis[i][j] = 100000;

		dis[a][b] = 1;
		while(scanf("%d%d", &a, &b)) {
			if(!a && !b) break;
			dis[a][b] = 1;
		}

		for(int k = 1; k <= 100; k++)
			for(int i = 1; i <= 100; i++) 
				for(int j = 1; j <= 100; j++) 
					dis[i][j] = min(dis[i][j], dis[i][k]+dis[k][j]);

		sum = 0;
		n = 0;
		for(int i = 1; i <= 100; i++) {
			for(int j = 1; j <= 100; j++) {
				if(i != j && dis[i][j] < 100000) {
					sum += dis[i][j];
					n++;
				}
			}
		}

		printf("Case %d: average length between pages = %.3lf clicks\n", ++cs, (double) sum/n);
	}

	return 0;
}
