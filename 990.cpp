#include <bits/stdc++.h>
using namespace std;

int n, w;
int d[31], v[31], dp[31][1001], taken[31][1001];
vector <int> result;

void printPath(int i, int t)
{
	if(i == n) return;

	if(taken[i][t]) {
		result.push_back(i);
		printPath(i+1, t-3*w*d[i]);
	}
	else printPath(i+1, t);
}

int f(int i, int t)
{
	if(i == n) return 0;

	if(dp[i][t] != -1) return dp[i][t];

	int p = 0, q = 0;

	if(t-3*w*d[i] >= 0) p = v[i] + f(i+1, t-3*w*d[i]);
	q = f(i+1, t);

	if(p > q) taken[i][t] = 1;

	return dp[i][t] = max(p, q);
}

int main()
{
	int flag = 0, t;
	while(scanf("%d%d", &t, &w) == 2) {
		scanf("%d", &n);
	
		memset(dp, -1, sizeof(dp));
		memset(taken, 0, sizeof(taken));
		result.clear();

		for(int i = 0; i < n; i++) scanf("%d%d", &d[i], &v[i]);

		if(flag) printf("\n");
		printf("%d\n", f(0, t));

		printPath(0, t);

		printf("%d\n", result.size());
		for(int i = 0; i < result.size(); i++) printf("%d %d\n", d[result[i]], v[result[i]]);

		flag = 1;
	}
	
	return 0;
}
