#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t, cs = 0;
	char a[1000];

	scanf("%d", &t);
	getchar();

	while(t--) {
		scanf("%s", a);
		int l = strlen(a);

		stack <char> st;
		map <char, int> mp;
		map <char, int>::iterator it;
		st.push(a[0]);

		for(int i = 1; i < l; i++) {
			if(a[i] == st.top()) st.pop();
			else {
				mp[st.top()]++;
				mp[a[i]]++;
				st.push(a[i]);
			}
		}

		printf("Case %d\n", ++cs);
		for(it = mp.begin(); it != mp.end(); it++) printf("%c = %d\n", it->first, it->second);
	}

	return 0;
}
