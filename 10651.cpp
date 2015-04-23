#include <bits/stdc++.h>
using namespace std;

int f(int mask, string a)
{
	int mn = 0;
	for(int i = 0; i < 12; ++i) if(a[i] == 'o') ++mn;

	for(int i = 0; i < 10; ++i) { 
		if(a[i] == '-' && a[i+1] == 'o' && a[i+2] == 'o') {
			string b = a;
			b[i] = 'o';
			b[i+1] = b[i+2] = '-';
			mn = min(mn, f(b));
		}
	}
	for(int i = 2; i < 12; ++i) {
		if(a[i] == '-' && a[i-1] == 'o' && a[i-2] == 'o') {
			string b = a;
			b[i] = 'o';
			b[i-1] = b[i-2] = '-';
			mn = min(mn, f(b));
		}
	}
	return mn;
}


int main()
{
	int t;
	string a;

	scanf("%d", &t);

	while(t--) {
		cin >> a;

		printf("%d\n", f(a));
	}

	return 0;
}
