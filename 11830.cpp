#include <bits/stdc++.h>
using namespace std;

int main()
{
	string b, c;
	char a;

	while(cin >> a >> b) {
		if(a == '0' && b == "0") break;
		
		c = "";

		int l = b.length();
		for(int i = 0; i < l; i++) if(b[i] != a) c += b[i];

		int i = 0;
		l = c.length();
		while(i < l && c[i] == '0') i++;
		if(i == l) {
			printf("0\n");
			continue;
		}
		for(; i < l; i++) printf("%c", c[i]);
		printf("\n");
	}

	return 0;
}
