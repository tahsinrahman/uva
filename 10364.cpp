#include <bits/stdc++.h>
using namespace std;

bool checkBit(int n, int i) { return n&(1<<i); }
int setBit(int n, int i) { return n|(1<<i); }

int flag, n, m;
int a[20];

void f(int mask, int val, int idx) {
	if(flag) return;

	if(mask == (1<<n)-1) {
		if(val == 0) flag = 1;
		return;
	}

	for(int i = idx; i < n; ++i) {
		if(flag) return;
		if(checkBit(mask, i)) continue;

		int tmp = val + a[i];

		if(tmp < m) f(setBit(mask, i), tmp, i+1);
		else if(tmp == m) f(setBit(mask, i), 0, 0);
	}
}

int main()
{
//	freopen("a.txt", "r", stdin);

	int t;
	scanf("%d", &t);

	while(t--) {
		scanf("%d", &n);

		int sum = 0;
		for(int i = 0; i < n; ++i) { scanf("%d", &a[i]); sum += a[i]; }

		if(sum%4) { printf("no\n"); continue; }

		m = sum/4;

		flag = 0;
		f(0, 0, 0);

		if(flag) printf("yes\n");
		else printf("no\n");
	}

	return 0;
}
