#include <bits/stdc++.h>
using namespace std;

vector <int> edge[2510];
int e, mx, day, mxday;

void bfs(int source)
{
	mxday = 0, mx = 0;

	vector <int> vis(e);
	vector <int> days(100);

	vis[source] = 1;

	queue <pair<int, int> > q;
	q.push(make_pair(source, 1));

	while(!q.empty()) {
		int u = q.front().first;
		int day = q.front().second;
		q.pop();

		for(int i = 0; i < edge[u].size(); i++) {
			int v = edge[u][i];

			if(!vis[v]) {
				vis[v] = 1;
				q.push(make_pair(v, day+1));
				days[day]++;
			}
		}
		if(days[day] > mx) {
			mx = days[day];
			mxday = day;
		}
			
	}
}


int main()
{
	int n, m, t;

	scanf("%d", &e);
	

	for(int i = 0; i < e; i++) {
		scanf("%d", &n);

		for(int j = 0; j < n; j++) {
			scanf("%d", &m);
			edge[i].push_back(m);
		}
	}

	scanf("%d", &t);
	while(t--) {
		scanf("%d", &m);
//		cout << bfs(m) << endl;
		bfs(m);
		if(mx == 0) printf("0\n");
		else printf("%d %d\n", mx, mxday);
	}

	return 0;
}
