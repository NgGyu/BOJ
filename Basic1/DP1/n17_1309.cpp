#include <iostream>
#define MOD 9901
#define NUM 100000
using namespace std;

void f(int n);
//long long mini(long long n1, long long n2, long long n3);
long long board[NUM +1][3] = { 0 };
//long long buf[3] = { 0 };
int main(void)
{
	
	int n;
	cin >> n;
	f(n);
		
	return 0;
}

void f(int n) {
	board[1][0] = 1;
	board[1][1] = 1;
	board[1][2] = 1;
	for (int i = 2; i <= n; i++) {
		board[i][0] = (board[i - 1][0] + board[i - 1][1] + board[i - 1][2]) % MOD;
		board[i][1] = (board[i - 1][0] + board[i - 1][2]) % MOD;
		board[i][2] = (board[i - 1][0] + board[i - 1][1]) % MOD;
	}
	long long ans = (board[n][0] + board[n][1] + board[n][2]) % MOD;
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