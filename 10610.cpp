#include <bits/stdc++.h>
using namespace std;

int n, dis[1012], velocity, m;
vector <int> edge[1012];
vector <double> cost[1012];

void bfs()
{
	for(int i = 0; i <= n; i++) dis[i] = INT_MAX;
	dis[0] = 0;

	queue <int> q;

	q.push(0);

	while(!q.empty()) {
		int u = q.front();
		q.pop();

		if(u == 1) return;

		int ucost = dis[u];

		for(int i = 0; i < edge[u].size(); i++) {
			int v = edge[u][i];
			
			if(1 + ucost < dis[v]) {
				dis[v] = 1+ucost;
				q.push(v);
			}
		}
	}
}



			

int main()
{
	double x[1012], y[1012];
	string a, b;

	while(scanf("%d%d", &velocity, &m)) {
		getchar();
		if(!m && !velocity) break;

		n = 0;
		while(getline(cin, a)) {
			if(a == "") break;
			stringstream ss(a);

			ss >> x[n] >> y[n];
			n++;
		}

		for(int i = 0; i < n; i++) {
			for(int j = i+1; j < n; j++) {
				double dist = sqrt( (x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]));
				if( dist > velocity*60.0*m) continue;
				edge[i].push_back(j);
				edge[j].push_back(i);
				cost[i].push_back(dist);
				cost[j].push_back(dist);
			}
		}

		bfs();

		if(dis[1] == INT_MAX) printf("No.\n");
		else printf("Yes, visiting %d other holes.\n", dis[1]-1);

		for(int i = 0; i <= n; i++) {
			edge[i].clear();
			cost[i].clear();
		}

	}

	return 0;
}
