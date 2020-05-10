#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> inp(n);
    for (int i = 0; i < n; i++) {
        cin >> inp[i];
    }
    if (prev_permutation(inp.begin(), inp.end())) {
        for (int i = 0; i < n; i++) {
            cout << inp[i] << ' ';
        }
    }
    else {
        cout << "-1";
    }
    cout << '\n';
    return 0;
}