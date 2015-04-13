#include <bits/stdc++.h>
using namespace std;

#define tt 1.0/sqrt(2)

void add(int n, double &x, double &y, char ch, char c)
{
	if(c == '.' || c == ',') {
		if(ch == 'N') y += n;
		else if(ch == 'S') y -= n;
		else if(ch == 'E') x += n;
		else if(ch == 'W') x -= n;
	}

	else {
		if(ch == 'N' && c == 'E') { y += (double) n*tt; x +=(double)  n*tt; }
		else if(ch == 'N' && c == 'W') { y += (double) n*tt; x -= (double) n*tt; }
		else if(ch == 'S' && c == 'E') { y -= (double) n*tt; x += (double) n*tt; }
		else if(ch == 'S' && c == 'W') { y -= (double) n*tt; x -= (double) n*tt; }
	}
}

int main()
{
	int cs = 0;
	char a[1000];

	while(scanf("%s", a) && a[0] != 'E') {
		int i = 0, l = strlen(a); 
		double x = 0, y = 0;

		printf("Map #%d\n", ++cs);
		while(i < l) {
			int n = 0;
			while(i < l && '0' <= a[i] && a[i] <= '9') { n = n*10+a[i]-'0'; ++i; }
			add(n, x, y, a[i], i+1<l?a[i+1]:'.');
			while(i < l && '0' > a[i] || a[i] > '9') ++i;
		}

		printf("The treasure is located at (%.3lf,%.3lf).\n", x+1e-9, y+1e-9);
		printf("The distance to the treasure is %.3lf.\n\n", sqrt(x*x+y*y)+1e-9);
	}

	return 0;
}
