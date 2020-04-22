#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> inp(n);
    for (int i = 0; i < n; i++) {
        inp[i] = i + 1;
    }
    do {
        for (int i = 0; i < n; i++) {
            cout << inp[i] << ' ';
        }
        cout << '\n';
    } while (next_permutation(inp.begin(), inp.end()));
    return 0;
}