#include <bits/stdc++.h>
using namespace std;

int n;
int a[100000], b[100000];

int bs(int h, int n) {
	int l = 1, ans = 0;

	while(l <= h) {
		int m = (l+h)>>1;

		if(n > a[b[m]]) h = m-1;
		else { ans = m; l = m+1; }
	}
	return ans+1;
}

int lis() {
	int len = 0;

	for(int i = 0; i < n; ++i) {
		int newL = bs(len, a[i]);
		b[newL] = i;
		len = max(len, newL);
	}
	return len;
}

int main() {
	int x, cs = 0;
	while(scanf("%d", &x) && x != -1) {
		n = 0;
		a[n++] = x;
		while(scanf("%d", &x) && x != -1) a[n++] = x;

		if(cs) printf("\n");
		printf("Test #%d:\n  maximum possible interceptions: %d\n", ++cs, lis());
	}

	return 0;
}
