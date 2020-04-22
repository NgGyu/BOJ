#include <iostream>
#include <algorithm>

#define MOD 10007
#define NUM 100000
using namespace std;

void f();

int E, S, M;

int main(void)
{

	
	cin >> E >> S >> M;
	
	f();


	return 0;
}

void f() {
    E -= 1;
    S -= 1;
    M -= 1;
    for (int i = 0;; i++) {
        if (i % 15 == E && i % 28 == S && i % 19 == M) {
            cout << i + 1 << '\n';
            break;
        }
    }
}
