#include <bits/stdc++.h>
using namespace std;

int parent[1000010];

int findset(int n)
{
	if(n != parent[n]) parent[n] = findset(parent[n]);
	return parent[n];
}

int main()
{
	int t, n, u, v, cs = 0;

	scanf("%d", &t);

	while(t--) {
		scanf("%d", &n);
		int a[n][n];

		for(int i = 0; i < n; i++) {
			scanf("%d", &a[i][0]);
			for(int j = 1; j < n; j++) {
				scanf(", %d", &a[i][j]);
			}
		}

		vector < pair <int, pair<int, int> > > edge;

		for(int i = 0; i < n; i++) 
			for(int j = i+1; j < n; j++) 
				if(a[i][j]) edge.push_back(make_pair(a[i][j], make_pair(i, j)));

		sort(edge.begin(), edge.end());

		for(int i = 0; i <= n; i++) parent[i] = i;

		printf("Case %d:\n", ++cs);
		for(int i = 0, s = edge.size(); i < s; i++) {
			u = findset(edge[i].second.first);
			v = findset(edge[i].second.second);

			if(u != v) {
				printf("%c-%c %d\n", 'A'+edge[i].second.first, 'A'+edge[i].second.second, edge[i].first);
				parent[u] = parent[v];
			}
		}
	}

	return 0;
}
