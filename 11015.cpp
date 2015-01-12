#include <bits/stdc++.h>
using namespace std;

int dis[40][40];

int main()
{
//	freopen("a.txt", "r", stdin);
	int n, m, meet, sum, mn, u, v, w, cs = 0;
	string a;

	while(scanf("%d%d", &n, &m) && n) {
		for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) if(i != j) dis[i][j] = 10000000;

		map <int, string> mp;

		for(int i = 1; i <= n; i++) {
			cin >> a;
			mp[i] = a;
		}

		while(m--) {
			scanf("%d%d%d", &u, &v, &w);
			dis[u][v] = min(dis[u][v], w);
			dis[v][u] = min(dis[v][u], w);
		}

		for(int k = 1; k <= n; k++) for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);

		mn = INT_MAX;
		for(int i = 1; i <= n; i++) {
			sum = 0;
			for(int j = 1; j <= n; j++) sum += dis[j][i];
			if(sum < mn) {
				mn = sum;
				meet = i;
			}
		}
	

		printf("Case #%d : ", ++cs);
		cout << mp[meet] << endl;
	}	

	return 0;
}
