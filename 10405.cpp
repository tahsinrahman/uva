#include <bits/stdc++.h>
using namespace std;

/*
//int n;
//int aa[100000], bb[100000];

//char a[100000], b[100000];

int bs(int h, int n) {
	int l = 1, ans = 0;

	while(l <= h) {
		int m = (l+h)>>1;

		if(aa[bb[m]] < n) {
			ans = m;
			l = m+1;
		}
		else h = m-1;
	}
	return ans+1;
}

int LIS() {
	int len = 0;

	for(int i = 0; i < n; ++i) {
		int newL = bs(len, aa[i]);
		bb[newL] = i;
		len = max(len, newL);
	}
	return len;
}

int LCS_LIS() {
	queue <int> idx[200];

	n = 0;
	for(int i = 0; a[i]; ++i) idx[a[i]].push(i+1);
	for(int i = 0; b[i]; ++i) {
		if(!idx[b[i]].empty()) {
			aa[n++] = idx[b[i]].front();
			idx[b[i]].pop();
		}
	}

	return LIS();
}
*/

char a[1010], b[1010];
int dp[1010][1010];

int lcs() {
	int n = strlen(a);
	int m = strlen(b);


	memset(dp, 0, sizeof(dp));
	for(int i = 1; i <= n; ++i) for(int j = 1; j <= m; ++j) dp[i][j] = max(max(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]+(a[i-1]==b[j-1]));
	return dp[n][m];
}


int main() {
	while(gets(a) != NULL) {
		gets(b);
		printf("%d\n", lcs());
	}

	return 0;
}
