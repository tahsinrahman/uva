#include <bits/stdc++.h>
using namespace std;

int l, n, result;
string a[100], b;
vector <string> ans;

void bt()
{
	if(result == l) {
		for(int i = 0; i < l; i++) cout << ans[i];
		printf("\n");
		return;
	}

	if(b[result] == '0') {
		for(int i = 0; i < 10; i++) {
			string aa = string(1, i+'0');
			ans.push_back(aa);
			result++;
			bt();
			result--;
			ans.pop_back();
		}
	}

	else {
		for(int i = 0; i < n; i++) {
			ans.push_back(a[i]);
			result++;
			bt();
			ans.pop_back();
			result--;
		}
	}
}

int main()
{
	int m;

	while(scanf("%d", &n) == 1) {
		printf("--\n");
		for(int i = 0; i < n; i++) cin >> a[i];

		scanf("%d", &m);

		while(m--) {
			cin >> b;
			l = b.length();

			result = 0;
			bt();
		}
	}

	return 0;
}
