#include <bits/stdc++.h>
using namespace std;

char a[1010], b[1010];
int dp[1010][1010];

bool check(char a) {
	if(('a' <= a && a <= 'z') || ('A' <= a && a <= 'Z') || ('0' <= a && a <= '9')) return 1;
	return 0;
}

int lcs() {
	for(int i = 0; a[i]; ++i) if(!check(a[i])) a[i] = ' ';
	for(int i = 0; b[i]; ++i) if(!check(b[i])) b[i] = ' ';

	stringstream ss;
	ss << a;

	string tmp;
	vector <string> aa, bb;
	while(ss >> tmp) aa.push_back(tmp);

	ss.clear();
	ss << b;
	while(ss >> tmp) bb.push_back(tmp);

	int n = aa.size();
	int m = bb.size();

	for(int i = 1; i <= n; ++i) for(int j = 1; j <= m; ++j) dp[i][j] = max(max(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]+(aa[i-1] == bb[j-1]));
	return dp[n][m];
}


int main() {
	int cs = 0;
	while(gets(a)) {
		gets(b);
		printf("%2d. ", ++cs);
		if(a[0] == NULL || b[0] == NULL) printf("Blank!\n");
		else printf("Length of longest match: %d\n", lcs());
	}

	return 0;
}
