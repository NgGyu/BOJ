#include <iostream>
#include <vector>
#include <algorithm>

#define INFINITE 9223372036854775808LL
#define MOD 1000000000LL;
#define limits 200

using namespace std;

void f(size_t sz, int last);
int n, k;


int idx[10];
int inp[10];
vector<vector<int>> buf;

int main(void)
{

    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> inp[i];
    }
    sort(inp, inp + n);
    f(0, 0);
    sort(buf.begin(), buf.end());
    buf.erase(unique(buf.begin(), buf.end()), buf.end());
    for (auto& v : buf) {
        for (int i = 0; i < k; i++) {
            cout << v[i];
            cout << ' ';
        }
        cout << '\n';
    }

    return 0;
}

void f(size_t sz, int last) {
    if (sz == k) {
        vector<int> tmp;
        for (int i = 0; i < k; i++) {
            tmp.push_back(inp[idx[i]]);
        }
        buf.push_back(tmp);
        return;
    }

    for (int i = last; i < n; i++) {
        

        idx[sz] = i;
        f(sz + 1, i);
    }
}