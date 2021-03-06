#include <iostream>
//#include <vector>

#define INFINITE 9223372036854775808LL
#define MOD 1000000000LL;
#define limits 200

using namespace std;

void f(size_t sz);
int n, k;

//std::vector<int> first;
//vector<int> v;
//vector<int>::iterator iter;
int isUsed[10] = {0};
int a[10];

int main(void)
{

    cin >> n >> k;
    f(0);
    return 0;
}

void f(size_t sz) {
    if (sz == k) {
        for (int i = 0; i < k; i++) {
            cout << a[i];
            if (i != k - 1) cout << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (isUsed[i] == 1) {
            continue;
        }
        
        a[sz] = i;
        isUsed[i] = 1;
        f(sz + 1);
        isUsed[i] = 0;
    }
}



