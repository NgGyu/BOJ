#include <iostream>
#include <algorithm>
using namespace std;
int a[9];
int n = 9;
int main() {
    int sum = 0;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    // 멤버가 아닌 난쟁이2명을 골라내는 경우의수를 모두 시험해보면 된다
    sort(a,a+n);
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            if (sum - a[i] - a[j] == 100) {
                for (int k=0; k<n; k++) {
                    if (i == k || j == k) continue;
                    cout << a[k] << '\n';
                }
                return 0;
            }
        }
    }
    return 0;
}