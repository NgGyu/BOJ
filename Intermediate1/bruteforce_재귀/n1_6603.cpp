#include <iostream>
#include <vector>
using namespace std;
int n;
int bench[100];
vector<int> lotto;
void bruteforce(int cnt, int idx) {
    if (cnt == 6) {
        for (int num : lotto) {
            printf("%d ", num);
        }
        printf("\n");
        return;
    }
    if (n == idx) return; //6개를 채우지 못한 조합
    //로또에 현재 idx포함
    lotto.push_back(bench[idx]);
    bruteforce(cnt + 1, idx + 1);
    //로또에 현재 idx미포함
    lotto.pop_back();
    bruteforce(cnt, idx + 1);
}
int main() {
    while (true) {
        cin >> n;
        //end
        if (n == 0) {
            break;
        }
        //cin
        for (int i = 0; i < n; i++) {
            cin >> bench[i];
        }
        bruteforce(0, 0);
        cout << '\n';
    }
    
    
    return 0;
}

