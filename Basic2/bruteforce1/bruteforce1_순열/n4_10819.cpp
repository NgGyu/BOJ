#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int n, sum;
    int ans = 0;
    cin >> n;
    vector<int> inp(n);
    for (int i = 0; i < n; i++) {
        cin >> inp[i];
    }
    sort(inp.begin(), inp.end());
    do {
        sum = 0;
        for (int i = 0; i < n-1; i++) {
            sum += abs(inp[i] - inp[i+1]);
        }
        ans = max(ans, sum);
    } while (next_permutation(inp.begin(), inp.end()));

    cout << ans;
    return 0;
}