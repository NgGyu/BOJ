#include <iostream>
#define SZ 100001
using namespace std;

int makeONE_td(int n);
int makeONE_bu(int n);
int board[SZ] = { 0 };

int main(void)
{
    int n;
    cin >> n;
	cout << makeONE_td(n) << endl;
	cout << makeONE_bu(n) << endl;
	return 0;
}

int makeONE_td(int n) {
	if (n == 1) return 0;
	if (board[n] > 0)
		return board[n];
	board[n] = makeONE_td(n - 1) + 1;
	if (n % 2 == 0) {
		int tmp = makeONE_td(n / 2) + 1;
		if (board[n] > tmp)
			board[n] = tmp;
	}
	if (n % 3 == 0) {
		int tmp = makeONE_td(n / 3) + 1;
		if (board[n] > tmp)
			board[n] = tmp;
	}
	return board[n];
}

int makeONE_bu(int n) {
	board[1] = 0;
	for (int i = 2; i <= n; i++) {
		board[i] = board[i - 1] + 1;
		if (i % 2 == 0 && board[i] > board[i / 2] + 1) {
			board[i] = board[i / 2] + 1;
		}

		if (i % 3 == 0 && board[i] > board[i / 3] + 1) {
			board[i] = board[i / 3] + 1;
		}
	}
	return board[n];
}