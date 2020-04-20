#include <iostream>
#define MOD 10000
#define NUM 10000
using namespace std;

void f();
long long maxi(long long n1, long long n2, long long n3);
//long long mini(long long n1, long long n2, long long n3);
long long inp[NUM + 1] = { 0 };
long long board[NUM + 1][3] = { 0 };
//long long buf[3] = { 0 };

int n, tmp;

int main(void)
{

	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> inp[i];
	}
	f();


	return 0;
}

void f() {
	board[1][0] = 0;
	board[1][1] = inp[1];
	board[1][2] = inp[1];

	for (int i = 2; i <= n; i++) {
		board[i][0] = maxi(board[i - 1][0], board[i - 1][1], board[i - 1][2]);
		board[i][1] = board[i - 1][0] + inp[i];
		board[i][2] = board[i - 1][1] + inp[i];
	}
	long long ans = maxi(board[n][0], board[n][1], board[n][2]);
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

long long maxi(long long n1, long long n2, long long n3) {
	long long ans;
	if (n1 > n2) {
		if (n1 > n3) {
			ans = n1;
		}
		else {
			ans = n3;
		}
	}
	else {
		if (n2 > n3) {
			ans = n2;
		}
		else {
			ans = n3;
		}
	}
	return ans;
}
