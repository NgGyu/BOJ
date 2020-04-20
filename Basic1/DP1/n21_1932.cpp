#include <iostream>
#define MOD 10000
#define NUM 500
using namespace std;

void f();
long long maxi(long long n1, long long n2);
//long long mini(long long n1, long long n2, long long n3);
long long inp[NUM + 1][NUM + 1] = { 0 };
long long board[NUM + 1][NUM + 1] = { 0 };
//long long buf[3] = { 0 };

int n, tmp;

int main(void)
{
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> inp[i][j];
		}
	}
	f();
	return 0;
}

void f() {
	board[1][1] = inp[1][1];

	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			if (j == 1) {
				board[i][j] = board[i - 1][j] + inp[i][j];
			}
			else if (j == i) {
				board[i][j] = board[i - 1][j - 1] + inp[i][j];
			}
			else {
				board[i][j] = maxi(
					board[i - 1][j - 1] + inp[i][j],
					board[i - 1][j] + inp[i][j]
					);
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (ans < board[n][i]) {
			ans = board[n][i];
		}
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

long long maxi(long long n1, long long n2) {
	long long ans;
	if (n1 > n2) {
		ans = n1;
	}
	else {
		ans = n2;
	}
	return ans;
}
