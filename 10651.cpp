#include <bits/stdc++.h>
using namespace std;

bool checkBit(int n, int i) { return n&(1<<i); }
int setBit(int n, int i) { return n|(1<<i); }
int resetBit(int n, int i) { return n&(~(1<<i)); }

int dp[1<<12];

int f(int mask) {
	if(dp[mask] != -1) return dp[mask];

	int mn = 0;
	for(int i = 0; i < 12; ++i) mn += checkBit(mask, i);

	for(int i = 0; i < 10; ++i) if(!checkBit(mask, i) && checkBit(mask, i+1) && checkBit(mask, i+2)) mn = min(mn, f(resetBit(resetBit(setBit(mask, i), i+1), i+2)));
	for(int i = 2; i < 12; ++i) if(!checkBit(mask, i) && checkBit(mask, i-1) && checkBit(mask, i-2)) mn = min(mn, f(resetBit(resetBit(setBit(mask, i), i-1), i-2)));

	return dp[mask] = mn;
}

int main()
{
	int t;
	char a[13];

	scanf("%d", &t);

	while(t--) {
		scanf("%s", a);

		int n = 0;
		for(int i = 0; i < 12; ++i) if(a[i] == 'o') n = setBit(n, i);
		
		memset(dp, -1, sizeof(dp));
		printf("%d\n", f(n));
	}

	return 0;
}
