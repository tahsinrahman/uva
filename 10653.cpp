#include <bits/stdc++.h>
using namespace std;

int graph[1000][1000], r, c, dis[1000][1000];

int bfs(int p, int q, int x, int y)
{
	for(int i = 0; i < r; i++) for(int j = 0; j < c; j++) dis[i][j] = INT_MAX;
	dis[p][q] = 0;

	queue <pair<int, int> > qq;
	qq.push(make_pair(p, q));

	while(!qq.empty()) {
		int a = qq.front().first;
		int b = qq.front().second;
		qq.pop();

		if(a == x && b == y) return dis[x][y];

		int ucost = dis[a][b];

		
		if(a+1 < r && graph[a+1][b] && 1+ucost < dis[a+1][b]) {
			dis[a+1][b] = 1+ucost;
			qq.push(make_pair(a+1, b));
		}
	
		if(a-1 >= 0 && graph[a-1][b] && 1+ucost < dis[a-1][b]) {
			dis[a-1][b] = 1+ucost;
			qq.push(make_pair(a-1, b));
		}

		
		if(b+1 < c && graph[a][b+1] && 1+ucost < dis[a][b+1]) {
			dis[a][b+1] = 1+ucost;
			qq.push(make_pair(a, b+1));
		}


		if(b-1 >= 0 && graph[a][b-1] && 1+ucost < dis[a][b-1]) {
			dis[a][b-1] = 1+ucost;
			qq.push(make_pair(a, b-1));
		}
	}
	return dis[x][y];
}


int main()
{
	int m, u, v, p, q, x, y;
	string a;
	
	while(scanf("%d%d", &r, &c)) {
		if(!r && !c) break;

		for(int i = 0; i < r; i++) for(int j = 0; j < c; j++) graph[i][j] = 1;

		scanf("%d", &m);
		getchar();

		while(m--) {
			scanf("%d", &u);
			scanf("%d", &x);

			while(x--) {
				scanf("%d", &v);
				graph[u][v] = 0;
			}
		}

//		for(int i = 0; i < r; i++) {
//			for(int j = 0; j < c; j++) cout << graph[i][j] <<' ';
//			cout << endl;
//		}

		scanf("%d%d%d%d", &p, &q, &x, &y);

		printf("%d\n", bfs(p, q, x, y));
	}

	return 0;
}
