#include <iostream>
#define MOD 1000000009LL
#define NUM 1000
using namespace std;

void f(int n);
long long mini(long long n1, long long n2, long long n3);
long long board[NUM +1][3] = { 0 };
long long buf[3] = { 0 };
int main(void)
{
	
	int n;
	cin >> n;
	f(n);
		
	return 0;
}

void f(int n) {
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> buf[j];
		}

		if (board[i - 1][1] > board[i - 1][2]) {
			board[i][0] = buf[0] + board[i - 1][2];
		}
		else {
			board[i][0] = buf[0] + board[i - 1][1];
		}

		if (board[i - 1][0] > board[i - 1][2]) {
			board[i][1] = buf[1] + board[i - 1][2];
		}
		else {
			board[i][1] = buf[1] + board[i - 1][0];
		}

		if (board[i - 1][0] > board[i - 1][1]) {
			board[i][2] = buf[2] + board[i - 1][1];
		}
		else {
			board[i][2] = buf[2] + board[i - 1][0];
		}
	}

	cout << mini(board[n][0], board[n][1], board[n][2]);
}

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