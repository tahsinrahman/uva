#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	string a;

	scanf("%d", &t);
	getchar();

	while(t--) {
		getline(cin, a);
		int l = a.length();

		int mx = 0;
		vector <char> v;
		vector <int> r(26);

		for(int i = 0; i < l; i++) {
			a[i] = tolower(a[i]);
			if('a' <= a[i] && a[i] <= 'z') {
				r[a[i]-'a']++;
				if(r[a[i]-'a'] > mx) {
					mx = r[a[i]-'a'];
					v.clear();
					v.push_back(a[i]);
				}
				else if(r[a[i]-'a'] == mx) v.push_back(a[i]);
			}
		}

		sort(v.begin(), v.end());

		for(int i = 0; i < v.size(); i++) printf("%c", v[i]);
		printf("\n");
	}


	return 0;
}
