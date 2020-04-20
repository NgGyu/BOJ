#include <iostream>
using namespace std;

int f(int n);
int board[1001] = { 0 };
int card[10001] = { 0 };
int main(void)
{
	int n, m;
	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		cin >> m;
		card[i] = m;
	}
	
	cout << f(n) << endl;

	return 0;
}

//어짜피 앞의 값들이 다 필요하므로 bottomup사용
int f(int n) {
	board[1] = card[1];
	
	for (int i = 2; i <= n; i++) {
		board[i] = card[i];
		for (int j = 1; j < i; j++) {
			if (board[i] < board[i - j] + card[j]) {
				board[i] = board[i - j] + card[j];
				
			}
			
		}
		//cout << i << "  " << board[i] << endl;
	}
	return board[n];
}