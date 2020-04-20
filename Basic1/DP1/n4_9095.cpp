#include <iostream>
using namespace std;

int f_td(int n);
int f_bu(int n);
int board[1001] = { 0 };
int card[10001] = { 0 };
int main(void)
{
	int n, m;
	cin >> n;
    
    for(int i=1;i<=n;i++){
        cin >> m;
        card[i] = m;
    }
    cout << f(n) <<endl;

	return 0;
}

int f(int n) {
	board[1] = card[1];
	board[2] = 2;
	board[3] = 4;
	for (int i = 4; i <= n; i++) {
		board[i] = board[i - 1] + board[i - 2] + board[i - 3];
	}
	return board[n];
}