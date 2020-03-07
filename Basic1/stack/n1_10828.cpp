// 변하는 문자열은 char[100], 변하지않는건 const char*, char[N] 반환시에는 char*
// 출력 : printf, fprintf, sprintf
// 입력 : 
// 1. 한글자씩 읽기 : getchar()
// 2. 한줄씩 읽기 : fgets() -> cnt-1개 만큼 읽어서 char*에 저장
// 3. 한데이터씩 읽기 : scanf(), fscanf, sscanf -> 공백문자버림
// best practice : fgets()로 한줄 읽어오고(실패하면 clearerr(), fflush()),
// sscanf로 버퍼에서 읽어온다.
#include <iostream>
#include <cstring>

#define CAPACITY 10000

using namespace std;


class Stack
{
    public:

    Stack()
    :sz(0)
    {}

    void push(int num){
        data[sz++] = num;
    }

    int pop(){

        if (empty()) {
            return -1;
        } else {
            sz -= 1;
            return data[sz];
        }
    }

    size_t size()
    {
        return sz;
    }

    int empty(){
        return (sz==0) ? 1 : 0;
    }

    int top(){
        if (empty()) {
            return -1;
        } else {
            return data[sz-1];
        }
    }

    private:
    int data[CAPACITY];
    size_t sz;
};

int main(void)
{
    Stack s;
    int n;
    char cmd[50];
    int param;
    fscanf(stdin, "%d", &n);

    while(n--){
        scanf("%s", cmd);
        if(!strcmp(cmd, "push")){
            fscanf(stdin, "%d", &param);
            s.push(param);
        }else if(!strcmp(cmd, "pop")){
            fprintf(stdout, "%d\n", s.pop());
        }else if(!strcmp(cmd, "size")){
            fprintf(stdout, "%d\n", s.size());
        }else if(!strcmp(cmd, "empty")){
            fprintf(stdout, "%d\n", s.empty());
        }else if(!strcmp(cmd, "top")){
            fprintf(stdout, "%d\n", s.top());
        }
    }
    return 0;
}