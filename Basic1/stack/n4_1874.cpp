#include <iostream>
#include <cstring>
#include <stack>

#define LINE_LENGTH 50

int main(void) {
	int n, seekNumber;
	int currentNumber = 1;
	std::stack<int> st;
    char ans[1000000];
    size_t cursor = 0;
	
	// # of testcase
	scanf("%d", &n);
	scanf("%d", &seekNumber);
	while (n) {
		// 비어있다면
		if (st.empty()) {
			st.push(currentNumber++);
			ans[cursor++] = '+';
            ans[cursor++] = '\n';
			continue;
		}
		//스택의 맨위에 찾고자하는 숫자가 있다면
		if (st.top() == seekNumber) {
			st.pop();
			ans[cursor++] = '-';
            ans[cursor++] = '\n';
			n--;
			if (n == 0) {
				break;
			}
			scanf("%d", &seekNumber);
		}
		else if (st.top() > seekNumber) {
			printf("NO");
			return 0;
		}
		else {
			st.push(currentNumber++);
			ans[cursor++] = '-';
            ans[cursor++] = '\n';
		}
	}
    ans[cursor] = '\0';
	std::cout << ans;
	return 0;
}