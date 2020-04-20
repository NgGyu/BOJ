#include <iostream>

#define limits 10
using namespace std;
void f();
long long board[limits + 1][4] = { 0 };
const long long mod = 1000000009LL;
int main(void)
{
	int n, T;
	cin >> T;
	f();
	for (int i = 1; i <= T; i++) {
		cin >> n;
		cout << board[n][1] + board[n][2] + board[n][3] << endl;
	}
	
	return 0;
}

void f() {
	board[1][1] = 1;
	board[1][2] = 0;
	board[1][3] = 0;
	board[2][1] = 0;
	board[2][2] = 1;
	board[2][3] = 0;
	board[3][1] = 1;
	board[3][2] = 1;
	board[3][3] = 1;
	
	for (int i = 4; i <= limits; i++) {
		
		board[i][3] = (board[i - 3][1] + board[i - 3][2]) % mod;
		board[i][2] = (board[i - 2][1] + board[i - 2][3]) % mod;
		board[i][1] = (board[i - 1][2] + board[i - 1][3]) % mod;
		
	}
}