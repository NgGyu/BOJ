#include <iostream>
#include <cstdlib>
// 주어진 모든 수의 gcd구하기

int gcd(int a, int b) {
	if (!b)
		return a;

	return gcd(b, a % b);
}

int main(void)
{
	int N, S;
	int ans, tmp;
	scanf("%d %d", &N, &S);
	
	scanf("%d", &ans);
	ans = abs(ans - S);
	while (--N)
	{
		scanf("%d", &tmp);
		ans = gcd(ans, abs(tmp - S));
	}
	printf("%d", ans);
	return 0;
}