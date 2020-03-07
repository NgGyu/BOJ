#include <iostream>
#include <cstring>


int main(void) {
	int cnt = 0;
	char buf;
	int bar = 0;
	int mode = 0;

	buf = getchar();
	while (buf!='\n') {
		
		if (buf == '(') {
			bar += 1;
			mode = 0;
		}
		else {
			bar -= 1;
			//레이저를 쏠 수 있음
			if (mode == 0) {
				cnt += bar;
			}
			else {
				cnt += 1;
			}
			mode = 1;
		}
		buf = getchar();
	}
	printf("%d", cnt);
	return 0;
}