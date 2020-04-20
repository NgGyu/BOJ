#include <iostream>

#define INFINITE 9223372036854775808
#define limits 30
using namespace std;
void f();
long long board[limits + 1] = { 0 };

int n;

int main(void)
{
	
	cin >> n;
	
	f();
	return 0;
}
//누적값을 저장해야하는 경우
void f() {
	board[2] = 3;
	long long cum = 1;
	for (int i = 4; i <= n; i += 2) {
		board[i] = 3 * board[i - 2] + 2 * cum;
		cum += board[i - 2];
	}
	cout << board[n];
}
