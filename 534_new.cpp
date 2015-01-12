#include <bits/stdc++.h>
using namespace std;

struct data {
	int city;
	double dist;
	bool operator < (const data &p) const {
		return dist > p.dist;
	}
};

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

		priority_queue <data> q;

		data u, v;

		u.city = 1;
		u.dist = 0;
		q.push(u);

		while(!q.empty()) {
			u = q.top();
			q.pop();
			double ucost = dis[u.city];

			for(int i = 0, s = e[u.city].size(); i < s; i++) {
				v.city = e[u.city][i];
				double vcost = max(ucost, c[u.city][i]);

				if(vcost < dis[v.city]) {
					dis[v.city] = vcost;
					q.push(v);
				}
			}
		}

		printf("Scenario #%d\nFrog Distance = %.3lf\n\n", ++cs, dis[0]);
	}

	return 0;
}
