#include <iostream>
#include <cstring>
#include <deque>

#define INP_SIZE 1000001

int main(void) {
	int n, k;
	std::deque<int> s;
	int* input = (int*)malloc(INP_SIZE * sizeof(int));
	int* res = (int*)malloc(INP_SIZE * sizeof(int));
	int* freq = (int*)calloc(INP_SIZE, sizeof(int));
	int i;

	scanf("%d", &n);
	k = n;

	for (i = 0; i < n; i++) {
		scanf("%d", &input[i]);
		freq[input[i]] += 1;
	}
	s.push_back(0);
	for (i = 1; i < n; i++) {
		if (s.empty()) {
			s.push_back(i);
		}
		while (!s.empty() && freq[input[s.back()]] < freq[input[i]]) {
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

	free(input);
	free(res);
	free(freq);
	return 0;
}