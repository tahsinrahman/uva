#include<bits/stdc++.h>
using namespace std;

int board[8][8], mx, taken[8][8];
vector <int> result;

void backtrack()
{
	if(result.size() == 8) {
		int sum = 0;

		for(int i = 0; i < 8; i++) sum += result[i];
		mx = max(mx, sum);

		return;
	}

	for(int i = 0; i < 8; i++) {
		int row = result.size();

		int f = 1;
		if(taken[row][i] == 0) {
			f = 0;

			result.push_back(board[row][i]);

			for(int j = row; j < 8; j++) taken[j][i]++;
			for(int j = row+1, k = i+1; j < 8 && k < 8; j++, k++) taken[j][k]++;
			for(int j = row+1, k = i-1; j < 8 && k >= 0; j++, k--) taken[j][k]++;

			backtrack();

			for(int j = row; j < 8; j++) taken[j][i]--;
			for(int j = row+1, k = i+1; j < 8 && k < 8; j++, k++) taken[j][k]--;
			for(int j = row+1, k = i-1; j < 8 && k >= 0; j++, k--) taken[j][k]--;

			result.pop_back();
		}
	}
}

	

int main()
{
	int t;

	scanf("%d", &t);

	while(t--) {
		for(int i = 0; i < 8; i++) for(int j = 0; j < 8; j++) scanf("%d", &board[i][j]);

		mx = 0;
		backtrack();

		printf("%5d\n", mx);
	}

	return 0;
}
