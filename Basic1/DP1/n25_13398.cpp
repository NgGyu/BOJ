#include <iostream>

#define INFINITE 9223372036854775808
#define limits 100000
using namespace std;
void f();
long long board[limits + 1] = { 0 };
long long ans[limits + 1] = { 0 };
long long ans2[limits + 1] = { 0 };
int n;

int main(void)
{
	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> board[i];
	}
	f();
	return 0;
}
//n24와 같은 접근방식
// O(N) 
void f() {
	ans[1] = board[1];
	for (int i = 2; i <= n; i++) {
		if (ans[i - 1] < 0) {
			ans[i] = board[i];
		}
		else {
			ans[i] = board[i] + ans[i - 1];
		}

	}

	ans2[n] = board[n];
	for (int i = n - 1; i >= 1; i--) {
		if (ans2[i + 1] < 0) {
			ans2[i] = board[i];
		}
		else {
			ans2[i] = board[i] + ans2[i + 1];
		}

	}
	//제거X
	long long res = (-1) * INFINITE;
	for (int i = 1; i <= n; i++) {
		if (ans[i] > res) {
			res = ans[i];
		}
	}
	//제거하는경우
	for (int i = 2; i <= n-1; i++) {
		if (ans[i-1] + ans2[i+1] > res) {
			res = ans[i - 1] + ans2[i + 1];
		}
	}
	cout << res << endl;
}
