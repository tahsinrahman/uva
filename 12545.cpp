#include <bits/stdc++.h>
using namespace std;

int main()
{
//	freopen("a.txt", "r", stdin);

	int tt, zero, one, s0, s1, t0, t1, cs = 0, ques;
	char s[200], t[200];

	scanf("%d", &tt);

	while(tt--) {
		scanf("%s", s);
		scanf("%s", t);

		int l = strlen(s);

		ques = s0 = s1 = t0 = t1 = 0;
		for(int i = 0; i < l; ++i) {
			if(s[i] == '?') ++ques;
			s[i] == '0'? ++s0 : ++s1;
			t[i] == '0'? ++t0 : ++t1;
		}

		printf("Case %d: ", ++cs);
		if(t0 > s0+ques) {
			printf("-1\n");
			continue;
		}

		zero = one = 0;
		for(int i = 0; i < l; ++i) {
			if(s[i] == '0' && t[i] == '1') ++zero;
			else if(s[i] == '1' && t[i] == '0') ++one;
		}

		printf("%d\n", ques + max(zero, one));
	}

	return 0;
}
