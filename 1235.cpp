#include <bits/stdc++.h>
using namespace std;

int parent[503];

int findset(int n)
{
	if(n != parent[n]) parent[n] = findset(parent[n]);
	return parent[n];
}

int main()
{
	int t, n, c, cost, ans, u, v;

	scanf("%d", &t);
	getchar();

	while(t--) {
		scanf("%d ", &n);
		char a[n+1][5];

		for(int i = 0; i < n; i++) scanf("%s", a[i]);

		c = INT_MAX;
		for(int i = 0; i < n; i++) {
			cost = 0;
			cost += a[i][0]<'5'?a[i][0]-'0':10-a[i][0]+'0';
			cost += a[i][1]<'5'?a[i][1]-'0':10-a[i][1]+'0';
			cost += a[i][2]<'5'?a[i][2]-'0':10-a[i][2]+'0';
			cost += a[i][3]<'5'?a[i][3]-'0':10-a[i][3]+'0';
			c = min(c, cost);
		}
		ans = c;
	

		vector <pair <int, pair <int, int> > > edge((n*(n-1))>>1);

		c = 0;
		for(int i = 0; i < n; i++) {
			for(int j = i+1; j < n; j++) {
				cost = 0;
				cost += min(abs(a[i][0]-a[j][0]), 10-abs(a[i][0]-a[j][0]));
				cost += min(abs(a[i][1]-a[j][1]), 10-abs(a[i][1]-a[j][1]));
				cost += min(abs(a[i][2]-a[j][2]), 10-abs(a[i][2]-a[j][2]));
				cost += min(abs(a[i][3]-a[j][3]), 10-abs(a[i][3]-a[j][3]));
				edge[c++] = make_pair(cost, make_pair(i, j));
			}
		}
		sort(edge.begin(), edge.end());

		for(int i = 0; i <= n; i++) parent[i] = i;

		for(int i = 0; i < c; i++) {
			u = findset(edge[i].second.first);
			v = findset(edge[i].second.second);

			if(u != v) {
				ans += edge[i].first;
				parent[u] = parent[v];
			}
		}
		printf("%d\n", ans);
	}

	return 0;
}
