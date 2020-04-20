#include <iostream>

#define INFINITE 9223372036854775808
#define limits 100000
using namespace std;
void f(int n);
long long board[limits + 1] = { 0 };
//long long ans[limits + 1] = { 0 };

int main(void)
{
	int n;
	cin >> n;
	/*
	for (int i = 1; i <= n;i++) {
		cin >> board[i];
	}
	*/
	f(n);
	return 0;
}

void f(int n) {
	board[1] = 1;
	for (int i = 2; i <= n; i++) {
		board[i] = i;
		for (int j = 1; j * j <= i; j++) {
			if (board[i] > board[i - j * j] + 1) {
				board[i] = board[i - j * j] + 1;
			}
		}
	}
	cout << board[n];
}
