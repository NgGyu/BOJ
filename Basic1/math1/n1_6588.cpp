//에라스토테네스의 체 이용
#include <iostream>

using namespace std;

const int MAX = 10000;
int prime[MAX];
int ptr;
bool check[MAX + 1] = { 0 };

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	//에라스토테네스의 체
	for (int i = 2; i <= MAX; i++) {
		if (check[i] == false) {
			prime[ptr++] = i;
			for (int j = i+i; j <= MAX; j += i) {
				check[j] = true;
			}
		}
	}
	while (true) {
		int n;
		cin >> n;
		if (n == 0) {
			break;
		}
		//2제외
		for (int i = 1; i < ptr; i++) {
			if (check[n - prime[i]] == false) {
				cout << n << " = " << prime[i] << " + " << n - prime[i] << '\n';
				break;
			}
		}
	}
	return 0;
}