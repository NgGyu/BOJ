#include <iostream>
#include <string>

using namespace std;
/*
void minus2(long long n) {
	if (n == 1) {
		printf("1");
		return;
	}
	if (n % 2 == -1) {
		minus2((n - 2) / -2);
		printf("1");
	}else if (n % 2 == 1) {
		minus2(n / -2);
		printf("1");
	}
	else {
		minus2(n / -2);
		printf("0");
	}

}
*/
int main(void)
{
	long long n;
	string s = "";
	scanf("%lld", &n);
	if (n == 0) {
		cout << 0;
		return 0;
	}
	while (n != 1) {
		
		if (n % 2 == -1) {
			n -= 2;
			s = "1" + s;
		}
		else if (n % 2 == 1) {
			s = "1" + s;
		}
		else {
			s = "0" + s;
		}
		n /= -2;
	}
	s = "1" + s;
	cout << s;
	return 0;
}