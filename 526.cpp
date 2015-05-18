#include <bits/stdc++.h>
using namespace std;

int cnt, cs;
int dp[82][82];
char a[82], b[82];

void printSolution(int n, int m) {
	int cs = 0, i = 0, j = 0, cnt = 0;
	while(i < n && j < m) {
		if(a[i] == b[j]) { ++i; ++j; }
		else if(dp[i][j] == 1+dp[i+1][j+1]) {
			printf("%d Replace %d,%c\n", ++cs, i+1+cnt, b[j]);
			++i;
			++j;
		}
		else if(dp[i][j] == 1+dp[i+1][j]) {
			printf("%d Delete %d, %c\n", ++cs, i+1+cnt, a[i]);
			--cnt;
			++i;
		}
		else if(dp[i][j] == 1+dp[i][j+1]) {
			printf("%d Insert %d,%c\n", ++cs, j+1, b[j]);
			++cnt;
			++j;
		}
	}
	while(i < n) {
		printf("%d Delete %d, %c\n", ++cs, i+1+cnt, a[i]);
		--cnt;
		++i;
	}
	while(j < m) {
		printf("%d Insert %d,%c\n", ++cs, j+1, b[j]);
		++j;
	}
}

int main() {
	int flag = 0;
	while(gets(&a[0])) {
		gets(&b[0]);

		if(flag) printf("\n");
		flag = 1;

		int n = strlen(a);
		int m = strlen(b);

		dp[n][m] = 0;
		for(int i = 0; i <= n; ++i) dp[i][m] = n-i;
		for(int i = 0; i <= m; ++i) dp[n][i] = m-i;

		for(int i = n-1; i >= 0; --i) for(int j = m-1; j >= 0; --j) dp[i][j] = min(min(dp[i+1][j], dp[i][j+1])+1, dp[i+1][j+1] + (a[i]!=b[j]));

		printf("%d\n", dp[0][0]);

		printSolution(n, m);

	}

	return 0;
}
