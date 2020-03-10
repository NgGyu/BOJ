#include <iostream>

using namespace std;

long long num_of_two(long long n) {
	long long res = 0;

	for (long long i = 2; i <= n; i *= 2) {
		res += n / i;
	}
	return res;
}
long long num_of_five(long long n) {
	
	long long res = 0;
	
	for (long long i = 5; i <= n; i *= 5) {
		res += n / i;
	}
	return res;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	long long n, m;
	long long nt, nf, mt, mf, nmt, nmf;
	long long two, five, ans;
	//소인수분해 5의갯수
	cin >> n >> m;

	nt = num_of_two(n);
	nf = num_of_five(n);
	mt = num_of_two(m);
	mf = num_of_five(m);
	nmt = num_of_two(n-m);
	nmf = num_of_five(n-m);
	two = nt - mt - nmt;
	five = nf - mf - nmf;
	ans = two > five ? five : two;
	cout << ans << "\n";

	return 0;
}