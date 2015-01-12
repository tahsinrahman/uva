#include <bits/stdc++.h>
using namespace std;

int main()
{
	string a;
	
	while(getline(cin, a)) {
		stringstream ss(a);

		vector <string> v;

		while(ss >> a) {
			reverse(a.begin(), a.end());
			v.push_back(a);
		}
		cout << v[0];
		for(int i = 1; i < v.size(); i++) cout << ' ' << v[i];
		cout << endl;
	}

	return 0;
}
