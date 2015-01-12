#include <bits/stdc++.h>
using namespace std;

#define inf 1e5

int main()
{
	printf("SHIPPING ROUTES OUTPUT\n");

	int t, n, m, p, u, v, cs = 0;
	string a, b;

	scanf("%d", &t);

	while(t--) {
		scanf("%d%d%d", &n, &m, &p);

		map <string, int> mp;
		vector <vector <int> > d(n+1, vector <int> (n+1));
		
		for(int i = 0; i < n; i++) {
			cin >> a;
			mp[a] = i;
		}

		while(m--) {
			cin >> a >> b;
			u = mp[a];
			v = mp[b];
			d[u][v] = 1;
			d[v][u] = 1;
		}

		for(int i = 0; i < n; i++) 
			for(int j = 0; j < n; j++) 
				if(i != j && !d[i][j]) d[i][j] = inf;

		for(int k = 0; k < n; k++) 
			for(int i = 0; i < n; i++) 
				for(int j = 0; j < n; j++) 
					d[i][j] = min(d[i][j], d[i][k]+d[k][j]);

		printf("\nDATA SET  %d\n\n", ++cs);
		while(p--) {
			cin >> m >> a >> b;
			u = mp[a];
			v = mp[b];
			if(d[u][v] == inf) printf("NO SHIPMENT POSSIBLE\n");
			else printf("$%d\n", 100*m*d[u][v]);
		}

	}
	printf("\nEND OF OUTPUT\n");

	return 0;
}
