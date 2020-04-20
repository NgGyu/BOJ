#include <iostream>
#define MOD 10007
#define NUM 100000
using namespace std;

void f(int n);
long long maxi(long long n1, long long n2, long long n3);
//long long mini(long long n1, long long n2, long long n3);
long long inp[NUM + 1][2] = { 0 };
long long board[NUM +1][3] = { 0 };
//long long buf[3] = { 0 };
int main(void)
{
	
	int n, col, tmp;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> col;
		for (int j = 1; j <= col; j++) {
			cin >> tmp;
			inp[j][0] = tmp;
		}
		for (int j = 1; j <= col; j++) {
			cin >> tmp;
			inp[j][1] = tmp;
		}
		f(col);
	}
	
	
		
	return 0;
}

void f(int n) {
	board[1][0] = inp[1][0];
	board[1][1] = inp[1][1];
	board[1][2] = 0;
	for (int i = 2; i <= n; i++) {
		board[i][0] = (board[i - 1][1] > board[i - 1][2] ?
			board[i - 1][1] : board[i - 1][2]) + inp[i][0];
		board[i][1] = (board[i - 1][0] > board[i - 1][2] ?
			board[i - 1][0] : board[i - 1][2]) + inp[i][1];
		board[i][2] = board[i - 1][0] > board[i - 1][1] ?
			board[i - 1][0] : board[i - 1][1];
	}
	long long ans = maxi(board[n][0], board[n][1], board[n][2]);

	cout << ans << endl;
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
