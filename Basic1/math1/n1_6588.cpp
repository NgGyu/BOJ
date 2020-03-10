//에라스토테네스의 체 이용
#include <iostream>

using namespace std;

const int MAX = 1000000;
int prime[MAX];
int ptr;
bool check[MAX + 1] = { 0 };

int main(void) {
	//에라스토테네스의 체
	for (int i = 2; i <= MAX; i++) {
		if (check[i] == false) {
			prime[ptr++] = i;
			for (int j = i+i; j <= MAX; j += i) {
				check[j] = true;
			}
		}
	}
	
	return 0;
}