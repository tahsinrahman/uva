#include <bits/stdc++.h>
using namespace std;


int main()
{
	int n, cs = 0;
	double d;

	while(scanf("%d", &n) && n) {
		int x[n], y[n];
		for(int i = 0; i < n; i++) scanf("%d%d", &x[i], &y[i]);

		vector <int> e[n];
		vector <double> c[n];

		for(int i = 0; i < n; i++) {
			for(int j = i+1; j < n; j++) {
				d = sqrt( (x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]) );
				e[i].push_back(j);
				e[j].push_back(i);
				c[i].push_back(d);
				c[j].push_back(d);
			}
		}

		vector <double> dis(n, 1000000000);
	
		dis[1] = 0;

		queue <int> q;
		q.push(1);

		while(!q.empty()) {
			int u = q.front();
			q.pop();
			double ucost = dis[u];

			for(int i = 0; i < e[u].size(); i++) {
				int v = e[u][i];
				double vcost = max(ucost, c[u][i]);

				if(vcost < dis[v]) {
					dis[v] = vcost;
					q.push(v);
				}
			}
		}


		printf("Scenario #%d\nFrog Distance = %.3lf\n\n", ++cs, dis[0]);
	}

	return 0;
}
