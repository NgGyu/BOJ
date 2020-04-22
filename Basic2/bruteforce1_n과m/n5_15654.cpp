#include <iostream>
#include <vector>
#include <algorithm>

#define INFINITE 9223372036854775808LL
#define MOD 1000000000LL;
#define limits 200

using namespace std;

void f(size_t sz);
int n, k;


vector<int> v;
int isUsed[10] = { 0 };
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
    f(0);
    return 0;
}

void f(size_t sz) {
    if (sz == k) {
        for (int i = 0; i < n; i++) {
            cout << a[i];
            if (i != n - 1) cout << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = 0; i < k; i++) {
        if (isUsed[i] == 1) {
            continue;
        }

        a[sz] = v[i];
        isUsed[i] = 1;
        f(sz + 1);
        isUsed[i] = 0;
    }
}