#include <iostream>

#define INFINITE 9223372036854775808
#define limits 100000
using namespace std;
void f(int n);
long long board[limits + 1] = { 0 };
long long ans[limits + 1] = { 0 };

int main(void)
{
	int n;
	cin >> n;
	for (int i = 1; i <= n;i++) {
		cin >> board[i];
	}
	f(n);
	return 0;
}

void f(int n) {
	ans[1] = board[1];
	for (int i = 2; i <= n; i++) {
		if (ans[i - 1] < 0) {
			ans[i] = board[i];
		}
		else {
			ans[i] = board[i] + ans[i - 1];
		}
		
	}
	long long res = (-1)*INFINITE;
	for (int i = 1; i <= n; i++) {
		if (ans[i] > res) {
			res = ans[i];
		}
	}
	cout << res << endl;
}
