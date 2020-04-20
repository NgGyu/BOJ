#include <iostream>

#define INFINITE 9223372036854775808LL
#define MOD 1000000000LL;
#define limits 200
using namespace std;
void f();
long long board[limits + 1][limits + 1] = { 0 };
//long long ans[limits + 1] = { 0 };
int n, k;
int main(void)
{

	cin >> n >> k;
	/*
	for (int i = 1; i <= n;i++) {
		cin >> board[i];
	}
	*/
	f();
	return 0;
}

void f() {
	board[0][0] = 1;
	for (int i = 1; i <= k; i++) {
		for (int j = 0; j <= n; j++) {
			board[i][j] += board[i - 1][j];
			if (j >= 1) {
				board[i][j] += board[i][j-1];
			}
			board[i][j] %= MOD;
		}
	}
	cout << board[k][n];
}
