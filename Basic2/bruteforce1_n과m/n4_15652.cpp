#include <iostream>
//#include <vector>

#define INFINITE 9223372036854775808LL
#define MOD 1000000000LL;
#define limits 200

using namespace std;

void f(size_t sz, int last);
int n, k;

//std::vector<int> first;
//vector<int> v;
//vector<int>::iterator iter;
int a[10];

int main(void)
{

    cin >> n >> k;
    f(0, 1);
    return 0;
}

void f(size_t sz, int last) {

    if (sz == k) {
        for (int i = 0; i < k; i++) {
            cout << a[i];
            if (i != k - 1) cout << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = last; i <= n; i++) {
        

        a[sz] = i;
        f(sz + 1, i);
    }
}



