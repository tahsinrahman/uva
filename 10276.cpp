#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t, n;

	scanf("%d", &t);

	while(t--) {
		scanf("%d", &n);

		if(n&1) printf("%d\n", (n+1)*((n+1)/2)-1);
		else printf("%d\n", (n/2)*n+n-1);
	}

	return 0;
}