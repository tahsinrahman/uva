#include <bits/stdc++.h>
using namespace std;

int main()
{
	string a;

	while(getline(cin, a)) {
		if(a == "DONE") break;

		string b = "";

		int l = a.length();
		for(int i = 0; i < l; i++) 
			if('a' <= a[i] && a[i] <= 'z' || 'A' <= a[i] && a[i] <= 'Z') {
				a[i] = tolower(a[i]);
				b += a[i];
			}

		a = b;
		reverse(a.begin(), a.end());

		if(a == b) printf("You won't be eaten!\n");
		else printf("Uh oh..\n");
	}

	return 0;
}
