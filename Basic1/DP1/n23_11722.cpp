#include <iostream>
#define MOD 10000
#define NUM 1000
using namespace std;

void f();
//long long mini(long long n1, long long n2, long long n3);
long long inp[NUM + 1] = { 0 };
long long board[NUM + 1] = { 0 };
//long long buf[3] = { 0 };

int n, tmp;

int main(void)
{
	cin >> n;
	for (int i = n; i >= 1; i--) {
		cin >> inp[i];
	}
	f();
	return 0;
}

void f() {
	
	for (int i = 1; i <= n; i++) {
		board[i] = 1;
		for (int j = 1; j < i; j++) {
			// check
			if (inp[j] < inp[i]) {
				if (board[j] + 1 > board[i]) {
					board[i] = board[j] + 1;
				}
			}
		}
	}
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		if (board[i] > ans) {
			ans = board[i];
		}
	}
	cout << ans;
}
