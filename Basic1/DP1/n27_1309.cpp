#include <iostream>

#define INFINITE 9223372036854775808
#define limits 100000
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
	board[0] = 1;
	long long cum = 1;
	for (int i = 1; i <= n; i++) {
		board[i] = (board[i - 1] + 2 * cum) % 9901;
		cum += board[i - 1];
	}
	cout << board[n];
}
