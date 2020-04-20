#include <iostream>
#define MOD 1000000009LL
#define NUM 1000000
using namespace std;

void f();
long long board[NUM +1] = { 0 };
int main(void)
{
	f();
	int n, m;
	cin >> n;
	while (n--) {
		cin >> m;
		cout << board[m] << '\n';
	}
		
	return 0;
}

void f() {
	board[1] = 1;
	board[2] = 2;
	board[3] = 4;
	for (int i = 4; i <= NUM; i++) {
		board[i] = board[i - 1] + board[i - 2] + board[i - 3];
		board[i] %= MOD;
	}
}