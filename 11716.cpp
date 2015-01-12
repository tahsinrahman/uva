#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	string a;

	scanf("%d", &n);
	getchar();

	while(n--) {
		getline(cin, a);
		int l = a.length();

		int n = sqrt(l);
		if(n*n != l) {
			printf("INVALID\n");
			continue;
		}

		for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) printf("%c", a[n*j+i]);
		printf("\n");
	}

	return 0;
}
