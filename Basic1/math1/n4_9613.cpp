#include <iostream>
using namespace std;
int gcd(int a, int b) {
	if (!b) 
		return a;
	
	return gcd(b, a % b);
}

int main(void)
{
	int n, m, i, j;
	long long ans;
	long long nums[101];
	cin >> n;
	while (n--) {
		ans = 0;
		cin >> m;
		for (i = 0; i < m; i++) {
			cin >> nums[i];
		}
		for (i = 0; i < m - 1; i++) {
			for (j = i + 1; j < m; j++) {
				ans += gcd(nums[i], nums[j]);
			}
		}
		cout << ans << '\n';
	}

	return 0;
}