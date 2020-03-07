#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

int main(void) {
	int n, m, val;
	int k = 1;
	
	// # of testcase
	scanf("%d %d", &n, &m);
	std::queue<int> q;
	for(int i=1;i<=n;i++){
		q.push(i);
	}
	printf("<");
	while(!q.empty()){
		val = q.front();
        q.pop();
		if((k++)%m==0){
			printf("%d", val);
            if(q.empty()){
                printf(">");
            }else{
                printf(", ");
            }
			continue;
		}
		q.push(val);
	}
	return 0;
}