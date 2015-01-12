#include <bits/stdc++.h>
using namespace std;

bool f(char ch)
{
	if('a' <= ch && ch <= 'z') return 1;
	if('A' <= ch && ch <= 'Z') return 1;
	return 0;
}

bool ff(char ch)
{
	if('0' <= ch && ch <= '9') return 1;
	return 0;
}


int main()
{
	string a;
	vector <string> v;

	while(getline(cin, a)) {
		if(a == "0") break;
		int l = a.length();

		int i = 0;
		while(i < l) {
			int p = i;
			int flag = 0;
			while(i < l && f(a[i])) {
				i++;
				flag = 1;
			}
			if(flag) {
				string b = a.substr(p, i-p);
				v.push_back(b);
				cout << b;
			}
			while(i < l && !f(a[i]) && !ff(a[i])) {
				cout << a[i];
				i++;
			}
			int n = 0;
			while(i < l && ff(a[i])) {
				n = n*10 + a[i]-'0';
				i++;
			}
			if(n) {
				string b = v[v.size()-n];
				cout << b;
				v.erase(v.begin()+v.size()-n);
				v.push_back(b);
			}
		}
		cout << endl;
	}


	return 0;
}
