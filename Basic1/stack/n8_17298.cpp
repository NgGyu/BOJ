#include <iostream>
#include <cstring>
#include <deque>

#define INP_SIZE 1000000

int main(void) {
	int n, m, k;
	std::deque<int> s;
	int input[INP_SIZE];
	int res[INP_SIZE];
	int i;

	scanf("%d", &n);
	k = n;

	for (i = 0; i < n; i++) {
		scanf("%d", &m);
		input[i] = m;
	}
	s.push_back(0);
	for (i = 1; i < n; i++) {
		if (s.empty()) {
			s.push_back(i);
		}
		while (!s.empty() && input[s.back()] < input[i]) {
			res[s.back()] = input[i];
			s.pop_back();
		}
		s.push_back(i);
	}
	while (!s.empty()) {
		res[s.back()] = -1;
		s.pop_back();
	}
	
	for (i = 0; i < k; i++) {
		printf("%d ", res[i]);
	}

	return 0;
}