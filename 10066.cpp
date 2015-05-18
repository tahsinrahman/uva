#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[1010], b[1010];
int dp[1010][1010];

int lcs() {
	for(int i = 1; i <= n; ++i) for(int j = 1; j <= m; ++j) dp[i][j] = max(max(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]+(a[i-1] == b[j-1]));
	return dp[n][m];
}


int main() {
	int cs = 0;
	while(scanf("%d%d", &n, &m)) {
		if(!n && !m) break;

		for(int i = 0; i < n; ++i) scanf("%d", &a[i]);
		for(int i = 0; i < m; ++i) scanf("%d", &b[i]);

		printf("Twin Towers #%d\nNumber of Tiles : %d\n\n", ++cs, lcs());
	}

	return 0;
}
