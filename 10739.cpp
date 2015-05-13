#include <bits/stdc++.h>
using namespace std;

char a[1002];
int dp[1002][1002];

int f(int i, int j) {
	if(i >= j) return 0;
	
	if(dp[i][j] != -1) return dp[i][j];

	return dp[i][j] = min(1+ min(f(i+1, j), f(i, j-1)), f(i+1, j-1) + (a[i] != a[j]));
}

int main() {
	int t, cs = 0;
	scanf("%d", &t);

	while(t--) {
		scanf("%s", a);

		int n = strlen(a);

		memset(dp, -1, sizeof(dp));
		printf("Case %d: %d\n", ++cs, f(0, n-1));
	}

	return 0;
}
