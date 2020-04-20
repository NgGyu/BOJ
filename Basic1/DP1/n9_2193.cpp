#include <iostream>

#define limits 100
using namespace std;
long long f(int n);
long long board[limits + 1][2] = { 0 };
int main(void)
{
	int n;
	cin >> n;
	cout << f(n) << endl;
	

	return 0;
}

long long f(int n) {
	board[1][0] = 0;
	board[1][1] = 1;
	for (int i = 2; i<=n; i++) {
		board[i][0] = board[i - 1][0] + board[i - 1][1];
		board[i][1] = board[i - 1][0];
		//cout << board[i][0]+ board[i][1] << endl;
	}
	
	
	return board[n][0]+board[n][1];
}