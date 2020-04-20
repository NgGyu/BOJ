#include <iostream>

#define limits 1000
using namespace std;
void f(int n);
void g(int n);
long long board[limits + 1] = { 0 };
long long ans[limits + 1] = { 0 };
long long V[limits + 1] = { 0 };

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
	ans[1] = 1;
	for (int i = 2; i <= n; i++) {
		ans[i] = 1;
		for (int j = 1; j < i; j++) {
			if (board[i] > board[j] && ans[i] < ans[j] + 1) {
				ans[i] = ans[j] + 1;
				V[i] = j;
			}
		}
	}
	long long res = 0;
	int idx = 0;
	for (int i = 1; i <= n; i++) {
		if (ans[i] > res) {
			res = ans[i];
			idx = i;
		}
	}
	cout << res << endl;
	g(idx);
}
void g(int n) {
	if (n == 0) return;
	g(V[n]);
	cout << board[n] << " ";
}