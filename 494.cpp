#include <bits/stdc++.h>
using namespace std;

int main()
{
	string a;
	
	while(getline(cin, a)) {
		int l = a.length();

		int i = 0, f = 0, n = 0;
		while(i < l) {
			f = 0;
			while(i < l && (('a' <= a[i] && a[i] <= 'z') || ('A' <= a[i] && a[i] <= 'Z' ))) {
				i++;
				f = 1;
			}
			if(f) n++;
			i++;
		}
		cout << n << endl;
	}

	return 0;
}
