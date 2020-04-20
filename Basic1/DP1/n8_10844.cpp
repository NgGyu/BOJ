#include <iostream>

#define limits 100
using namespace std;
int f(int n);
long long board[limits + 1][10] = { 0 };
const long long mod = 1000000000LL;
int main(void)
{
	int n;
	cin >> n;
	cout << f(n) << endl;
	

	return 0;
}

int f(int n) {
	for (int i = 1; i < 10; i++) {
		board[1][i] = 1;
	}
	for (int i = 2; i<=n; i++) {
		for (int j = 0; j < 10; j++) {
			board[i][j] = 0;
			if (j < 9) {
				board[i][j] += board[i - 1][j + 1];
			}
			if (j > 0) {
				board[i][j] += board[i - 1][j - 1];
			}
			board[i][j] %= mod;
		}
	}
	long long res = 0;
	for (int i = 0; i < 10; i++) {
		res += board[n][i];
	}
	return (res % mod);
	
}