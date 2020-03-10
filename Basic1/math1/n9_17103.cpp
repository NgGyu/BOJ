#include <iostream>
using namespace std;
int main(void) {
	const int MAX = 1000001;
	int prime[MAX];
	int ptr = 0;
	bool check[MAX + 1] = { 0 };
	int n, m, cnt;
	//에라스토테네스의 체
	for (int i = 2; i <= MAX; i++) {
		if (check[i] == false) {
			prime[ptr++] = i;
			for (int j = i + i; j <= MAX; j += i) {
				check[j] = true;
			}
		}
	}
	
	scanf("%d", &n);
	while (n--)
	{
		cnt = 0;
		scanf("%d", &m);
		for (int j = 2; j <= m / 2; j++) {
			//소수가 아닌 경우
			if (check[j]) continue;
			// 소수 j에대하여 m-j도 소수라면 cnt++
			if (!check[m - j]) {
				cnt++;
			}
		}
		printf("%d\n", cnt);
	}
	
	return 0;
}