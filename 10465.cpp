#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, m, t, p, q;

	while(scanf("%d%d%d", &m, &n, &t) == 3) {
		vector <int> dp(10010);

		for(int i = min(n, m); i <= t; ++i) {
			p = q = 0;
			if(i-n >= 0 && (i == n || dp[i-n])) p = 1+dp[i-n];
			if(i-m >= 0 && (i == m || dp[i-m])) q = 1+dp[i-m];
			dp[i] = max(p, q);
		}
		if(dp[t]) printf("%d\n", dp[t]);
		else {
			for(int i = t-1; i >= 0; --i) {
				if(dp[i]) {
					printf("%d %d\n", dp[i], t-i);
					break;
				}
				else if(!i) printf("0 %d\n", t);
			}
		}

	}

	return 0;
}
