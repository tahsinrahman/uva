#include <bits/stdc++.h>
using namespace std;

double dis[102][102];

int main()
{
//	freopen("a.txt", "r", stdin);

	int t, n, cs = 0;
	double mx;
	
	scanf("%d", &t);

	while(t--) {
		scanf("%d", &n);
		int x[n], y[n];

		for(int i = 0;  i < n; i++) for(int j = 0; j < n; j++) if(i != j) dis[i][j] = 10000000;

		for(int i = 0; i < n; i++) scanf("%d%d", &x[i], &y[i]);

		for(int i = 0; i < n; i++) {
			for(int j = i+1; j < n; j++) {
				double d = sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
				if(d <= 10) {
					dis[i][j] = d;
					dis[j][i] = d;
				}
			}
		}

		for(int k = 0; k < n; k++) for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);

		mx = 0;
		for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) mx = max(mx, dis[i][j]);
		
		printf("Case #%d:\n", ++cs);
		if(mx >= 10000000) printf("Send Kurdy\n");
		else printf("%.4lf\n", mx);
		printf("\n");
	}

	return 0;
}
