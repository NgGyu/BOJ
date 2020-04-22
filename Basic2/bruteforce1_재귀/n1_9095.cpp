// 9095. 1,2,3 더하기
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//int list[12];
void f(int sum, int how_many, int target, int* count);

int main() {
    int n, k, cnt;
    
    cin >> n;
    while (n--) {
        cnt = 0;
        cin >> k;
        f(0, 0, k, &cnt);
        cout << cnt << "\n";
    }
    return 0;
}
void f(int sum, int how_many, int target, int* count) {
    if (sum == target) {
        (*count)++;
        return;
    }
    if (sum > target) {
        return;
    }
    for (int i = 1; i <= 3; i++) {
        f(sum+i, how_many+1, target, count);
    }
}
