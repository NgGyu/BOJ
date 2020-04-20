#include <iostream>
#include <vector>
#include <algorithm>

#define INFINITE 9223372036854775808LL
#define MOD 1000000000LL;
#define limits 200

using namespace std;

void f(size_t sz, int last);
int n, k;


vector<int> v;
int a[10];

int main(void)
{

    cin >> n >> k;
    int tmp;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    f(0, 0);
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

    for (int i = last; i < n; i++) {
        

        a[sz] = v[i];
        f(sz + 1, i);
    }
}