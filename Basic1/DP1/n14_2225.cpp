#include <iostream>

#define INFINITE 9223372036854775808LL
#define MOD 1000000000LL;
#define limits 200
using namespace std;
void f(int n, int k);
long long board[limits + 1][limits + 1] = { 0 };
//long long ans[limits + 1] = { 0 };

int main(void)
{
	int n, k;
	cin >> n >> k;
	/*
	for (int i = 1; i <= n;i++) {
		cin >> board[i];
	}
	*/
	f(n, k);
	return 0;
}

void f(int n, int k) {
	board[0][0] = 1;
	for (int i = 1; i <= k; i++) {
		for (int j = 0; j <= n; j++) {
			for (int l = 0; l <= j; l++) {
				board[i][j] += board[i - 1][j - l];
				board[i][j] %= MOD;
			}
		}
	}
	cout << board[k][n];
}
