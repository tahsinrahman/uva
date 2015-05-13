#include <bits/stdc++.h>
using namespace std;

int cnt, cs;
int dp[82][82];
char a[82], b[82];

void f(int i, int j) {
	if(!i && !j) return;

	if(!i) {
		for(int i = 1; i <= j; ++i) {
//			printf("%d Insert %d,%c\n", ++cs, i, b[i-1]);
			printf("I%c", b[i-1]);
			if(i < 10) printf("0%d", i);
			else printf("%d", i);
			++cnt;
		}
		return;
	}

	if(!j) {
		for(int j = 1; j <= i; ++j) {
//			printf("%d Delete %d\n", ++cs, i+cnt);
			printf("D%c", a[i+cnt-1]);
			if(i+cnt < 10) printf("0%d", i+cnt);
			else printf("%d", i+cnt);
			--cnt;
		}
		return;
	}


	if(dp[i][j] == dp[i-1][j-1] && a[i-1] == b[j-1]) {
		f(i-1, j-1);
		return;
	}

	if(dp[i][j] == 1+dp[i-1][j-1]) {
		f(i-1, j-1);
//		printf("%d Replace %d,%c\n", ++cs, i+cnt, b[j-1]);
		printf("C%c", b[j-1]);
		if(i+cnt < 10) printf("0%d", i+cnt);
		else printf("%d", i+cnt);
		return;
	}

	if(dp[i][j] == 1+dp[i-1][j]) {
		f(i-1, j);
//		printf("%d Delete %d\n", ++cs, i+cnt);
		printf("D%c", a[i-1]);
//		cout << endl << i << ' ' << j << ' ' << cnt << endl;
		if(i+cnt < 10) printf("0%d", i+cnt);
		else printf("%d", i+cnt);
		--cnt;
		return;
	}
	if(dp[i][j] == 1+dp[i][j-1]) {
		f(i, j-1);
		++cnt;
//		printf("%d Insert %d,%c\n", ++cs, i+cnt, b[j-1]);
		printf("I%c", b[j-1]);
		if(i+cnt < 10) printf("0%d", i+cnt);
		else printf("%d", i+cnt);
		return;
	}


}


int main() {
	int flag = 0;
//	while(gets(&a[0])) {
//		gets(&b[0]);
	while(scanf("%s", a)) {
		if(a[0] == '#') break;
		
		scanf("%s", b);

//		if(flag) printf("\n");
//		flag = 1;

		int n = strlen(a);
		int m = strlen(b);

		dp[0][0] = 0;
		for(int i = 1; i <= n; ++i) dp[i][0] = i;
		for(int i = 1; i <= m; ++i) dp[0][i] = i;

		for(int i = 1; i <= n; ++i) for(int j = 1; j <= m; ++j) dp[i][j] = min(min(dp[i-1][j], dp[i][j-1])+1, dp[i-1][j-1] + (a[i-1]!=b[j-1]));

//		printf("%d\n", dp[n][m]);
		cs = 0;

		cnt = 0;
		f(n, m);
		printf("E\n");
	}

	return 0;
}
