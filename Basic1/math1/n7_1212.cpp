#include <iostream>
#include <cstring>
#define MAXSIZE 333335

int main(void)
{
	char foct2bin[8][4] = {
		"0", "1", "10", "11", "100", "101", "110", "111"
	};
	char oct2bin[8][4] = {
		"000", "001", "010", "011", "100", "101", "110", "111"
	};

	char* oct = (char*)malloc(MAXSIZE);
	scanf("%s", oct);
	int n = strlen(oct);
	int m = n-1;
    
	n--;
	printf("%s", foct2bin[oct[m - n] - '0']);

	while (n--)
	{
		printf("%s", oct2bin[oct[m-n]-'0']);
	}
	return 0;
}