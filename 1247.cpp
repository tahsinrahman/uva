#include <bits/stdc++.h>
using namespace std;

int dis[30][30], parent[30][30];;
vector <int> path;

void findpath(int u, int v)
{
	if(parent[u][v] == -1) printf("%c ", u+'A');
	else {
		findpath(u, parent[u][v]);
		findpath(parent[u][v], v);
	}
}


int main()
{
//	freopen("a.txt", "r", stdin);

	int n, m, w, q;
	char u, v;


	memset(parent, -1, sizeof(parent));
	for(int i = 0; i < 26; i++) 
		for(int j = 0; j < 26; j++)
			if(i != j) dis[i][j] = 100000;

	scanf("%d %d", &n, &m);
	getchar();

	while(m--) {
		scanf("%c %c %d", &u, &v, &w);
		getchar();
		dis[u-'A'][v-'A'] = w;
		dis[v-'A'][u-'A'] = w;
	}

	for(int k = 0; k < 26; k++) 
		for(int i = 0; i < 26; i++) 
			for(int j = 0; j < 26; j++)
				if(dis[i][k] + dis[k][j] < dis[i][j]) {
					dis[i][j] = dis[i][k] + dis[k][j];
					parent[i][j] = k;
				}



	scanf("%d", &q);
	getchar();
	while(q--) {
		scanf("%c %c", &u, &v);
		getchar();
		findpath(u-'A', v-'A');
		printf("%c\n", v);
	}

	return 0;
}
