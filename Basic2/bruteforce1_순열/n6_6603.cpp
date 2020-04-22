// 중복순열/조합도 permutation이용해서 할 수 있다.
// 6603 로또
#include <iostream>
#include <algorithm>
#include <vector>

int candidate[15];
using namespace std;
int main() {
    int n, tmp;
    while (1) {
        cin >> n;

        if (n == 0) return 0;
        tmp = 0;
        vector<int> isChoosed(n);
        for (int i = 0; i < n; i++) {
            cin >> candidate[i];
            if (tmp++ < 6) {
                isChoosed[i] = 0;
            }
            else {
                isChoosed[i] = 1;
            }
        }
        

        do {
            
            for (int i = 0; i < n; i++) {
                if (!isChoosed[i]) {
                    cout << candidate[i] << " ";
                }
            }
            cout << "\n";
            
        } while (next_permutation(isChoosed.begin(), isChoosed.end()));
        cout << "\n";
    }
    
    
    
    //sort(perm.begin(), perm.end());
    
    
    
    return 0;
}