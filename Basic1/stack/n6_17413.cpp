#include <iostream>
#include <cstring>
#include <deque>


int main(void) {
	int mode = 1;
	char buf;
	std::deque<char> deq;

	
	while (1) {
		buf = getchar();
		if (buf == ' ' || buf == '<' || buf == '>' || buf=='\n') {
			if (mode == 1) { //<>밖에있다면
				for (auto it = deq.crbegin(); it != deq.crend(); it++) {
					printf("%c", *it);
				}
			}
			else { //<>안에있다면 
				for (auto it = deq.cbegin(); it != deq.cend(); it++) {
					printf("%c", *it);
				}
			}
			deq.clear();
			if (buf == '<') {
				mode = 2;
			}
			else if (buf == '>') {
				mode = 1;
			}
			printf("%c", buf);
			//종료 조건
			if (buf == '\n') {
				break;
			}
		}else {
			deq.push_back(buf);
		}
	}
	return 0;
}