#include<bits/stdc++.h>
using namespace std;

int sum, h, n;
string a;

void bt(int idx)
{
	if(sum == h) {
		cout << a << endl;
		return;
	}

	for(int i = idx; i < n; i++) {
		if(sum < h) {
			sum++;
			a[i] = '0';

			bt(i+1);

			sum--;
			a[i] = '1';
		}
	}
}

int main()
{
	int t;

	scanf("%d", &t);

	while(t--) {
		scanf("%d%d", &n, &h);
		h = n-h;

		a = string(n, '1');

		bt(0);
		if(t) printf("\n");
	}

	return 0;
}