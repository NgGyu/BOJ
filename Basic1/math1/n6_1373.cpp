#include <iostream>
#include <cstring>
#define MAXSIZE 1000001


int main(void)
{
	char* binary = (char*)calloc(MAXSIZE, sizeof(char));
	char* res = (char*)malloc(MAXSIZE);
	scanf("%s", binary);
	
	int n = strlen(binary);
	int curr = 0;
	int ans;

	if (n % 3 == 2) {
		curr = 2;
		ans = 0;
        if (binary[0] == '1') {
			ans += 2;
		}
		if (binary[1] == '1') {
			ans += 1;
		}
		printf("%d", ans);
	}

	if (n % 3 == 1) {
		curr = 1;
        ans = 0;
        if (binary[0] == '1') {
			ans += 1;
		}
		printf("%d", ans);
	}
	
	while (curr!=n)
	{
		ans = 0;
		if (binary[curr++] == '1') {
			ans += 4;
		}
		if (binary[curr++] == '1') {
			ans += 2;
		}
		if (binary[curr++] == '1') {
			ans += 1;
		}
		printf("%d", ans);
	}

	return 0;
}