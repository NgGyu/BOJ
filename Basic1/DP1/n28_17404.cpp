#include <iostream>
#include <algorithm>

#define INFINITE 9023372036854775808
#define limits 1000

using namespace std;

void f();
long long inp[limits + 1][3] = { 0 };
long long board[limits + 1][3] = { 0 };

int n;

int main(void)
{
	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> inp[i][j];
		}
	}
	f();
	return 0;
}

void f() {
	long long ans = INFINITE;
	for (int color = 0; color <= 2; color++) {
		// 1번집
		for (int i = 0; i <= 2; i++) {
			if (i == color) {
				board[1][i] = inp[1][i];
			}
			else {
				board[1][i] = INFINITE;
			}
		}
		for (int i = 2; i <= n; i++) {
			board[i][0] = min(board[i - 1][1], board[i - 1][2]) + inp[i][0];
			board[i][1] = min(board[i - 1][0], board[i - 1][2]) + inp[i][1];
			board[i][2] = min(board[i - 1][0], board[i - 1][1]) + inp[i][2];
		}
		
		for (int i = 0; i <= 2; i++) {
			//n번집과 1번집 색 같은 경우는 최소값후보에서 제외
			if (i == color) {
				continue;
			}
			ans = min(ans, board[n][i]);
		}
	}
	cout << ans << '\n';
}
