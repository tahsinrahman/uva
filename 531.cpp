#include <bits/stdc++.h>
using namespace std;

char a[1010];
int dp[1010][1010];
vector <string> aa, bb;

void lcs() {
	int n = aa.size(), m = bb.size();
	for(int i = 1; i <= n; ++i) for(int j = 1; j <= m; ++j) dp[i][j] = max(max(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]+(aa[i-1] == bb[j-1]));

	vector <string> res;
	while(n && m) {
		if(aa[n-1] == bb[m-1]) {
			res.push_back(aa[n-1]);
			--n;
			--m;
		}
		else if(dp[n-1][m] >= dp[n][m-1]) --n;
		else --m;
	}
	reverse(res.begin(), res.end());
	cout << res[0];
	for(int i = 1, s = res.size(); i < s; ++i) cout << ' ' << res[i];
	printf("\n");
}


int main() {
	while(gets(a) != NULL) {
		stringstream s(a);
		string tmp;
		while(s >> tmp) aa.push_back(tmp);
		while(gets(a)) {
			if(a[0] == '#') break;
			stringstream ss(a);
			string tmp;
			while(ss >> tmp) aa.push_back(tmp);
		}
		while(gets(a)) {
			if(a[0] == '#') break;
			stringstream ss(a);
			string tmp;
			while(ss >> tmp) bb.push_back(tmp);
		}
		/*
		for(int i = 0; i < aa.size(); ++i) cout << aa[i] << ' ';
		cout << endl;
		for(int i = 0; i < bb.size(); ++i) cout << bb[i] << ' ';
		cout << endl;
		cout << "lcs" << endl;
		*/
		lcs();
		aa.clear();
		bb.clear();
	}

	return 0;
}
