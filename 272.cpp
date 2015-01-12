#include <bits/stdc++.h>
using namespace std;

int main()
{
	string a;
	int f = 1;
	while(getline(cin, a)) {
		int l = a.length();

		for(int i = 0; i < l; i++) {
			if(a[i] != '"') {
				printf("%c", a[i]);
				continue;
			}
			if(f) printf("``");
			else printf("''");
			f = 1-f;
		}
		printf("\n");
	}

	return 0;
}
