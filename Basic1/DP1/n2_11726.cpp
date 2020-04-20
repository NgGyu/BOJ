#include <iostream>
#define SZ 1001
using namespace std;

int tile2n_td(int n);
int tile2n_bu(int n);
int board[SZ] = { 0 };

int main(void)
{
	int n;
	cin >> n;
	cout << tile2n_td(n) << endl;
	cout << tile2n_bu(n) << endl;
	return 0;
}

int tile2n_td(int n) {
	if (n == 1) return 1;
	if (n == 2) return 2;
	if (board[n] > 0)
		return board[n];
	board[n] = (tile2n_td(n - 1) + tile2n_td(n - 2)) % 10007;
	
	return board[n];
}

int tile2n_bu(int n) {
	board[1] = 1;
	board[2] = 2;
	for (int i = 3; i <= n; i++) {
		board[i] = (board[i - 1] + board[i - 2]) % 10007;
	}
	return board[n];
}