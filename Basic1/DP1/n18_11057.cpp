#include <iostream>
#define MOD 10007
#define NUM 1000
using namespace std;

void f(int n);
//long long mini(long long n1, long long n2, long long n3);
long long board[NUM +1][10] = { 0 };
//long long buf[3] = { 0 };
int main(void)
{
	
	int n;
	cin >> n;
	f(n);
		
	return 0;
}

void f(int n) {
	for (int i = 0; i < 10; i++) {
		board[1][i] = 1;
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = j; k < 10; k++) {
				board[i][j] = (board[i][j] + board[i - 1][k]) % MOD;
			}
		}
	}
	long long ans = 0;

	for (int i = 0; i < 10; i++) {
		ans = (ans + board[n][i]) % MOD;
	}
	cout << ans;
}
/*
long long mini(long long n1, long long n2, long long n3) {
	long long ans;
	if (n1 > n2) {
		if (n2 > n3) {
			ans = n3;
		}
		else {
			ans = n2;
		}
	}
	else {
		if (n1 > n3) {
			ans = n3;
		}
		else {
			ans = n1;
		}
	}
	return ans;
}
*/