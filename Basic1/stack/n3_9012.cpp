#include <iostream>
#include <cstring>
#include <stack>

#define LINE_LENGTH 50

int main(void) {
	int n;
	char buffer[LINE_LENGTH + 1];
	char dummy[1000];
    size_t buf_length;
    int flag;


	// # of testcase
	scanf("%d", &n);
    // 버퍼비우기
	fgets(dummy, LINE_LENGTH, stdin);
	while (n--) {
        fgets(buffer, LINE_LENGTH, stdin);
        //buffer에서 개행문자 NULL로 바꿔줌 
        buf_length = strlen(buffer)-1;
		buffer[buf_length] = '\0';
        //초기화
        flag=0;
        std::stack<char> st;
        
        for(int i=0;i<buf_length;++i){
            if(buffer[i]=='('){
                st.push('(');
            }else if(buffer[i]==')'){
                if(st.empty()){
                    flag=1;
                    break;
                }
                st.pop();
            }
        }
        //판정
        if(flag==1 || !st.empty()){
            printf("NO\n");
        }else{
            printf("YES\n");
        }
        
	}
	return 0;
}