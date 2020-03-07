#include <iostream>
#include <cstring>
#include <stack>

#define MAX_LINE 1000
#define MAX_WORD 20

int main(void) {
	int n;
	char buffer[MAX_LINE + 1];
	char word[MAX_WORD + 1];
	char* token;
	char dummy[1000];
	std::stack<char> st;
	int cnt;


	// # of testcase
	scanf("%d", &n);
	// \n버림
	fgets(dummy, 1000, stdin);
	while (n--) {
		//맨끝의 개행문자제거
		fgets(buffer, 1000, stdin);
		buffer[strlen(buffer) - 1] = '\0';

		token = std::strtok(buffer, " ");
		while (token != NULL) {
		
			//word로 복사(최대길이20, \0 나오는곳 전까지)
			strncpy(word, token, 20);
			cnt = 0;
			while (word[cnt]!='\0') {
				st.push(word[cnt++]);
			}
			while (!st.empty()) {
				printf("%c", st.top());
				st.pop();
			}
			printf(" ");
			//다음 토큰
			token = std::strtok(NULL, " ");
		}
		printf("\n");
	}
	return 0;
}