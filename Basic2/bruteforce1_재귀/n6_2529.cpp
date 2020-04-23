#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

int check(int len, char(&nums)[11],
    char(&inequal)[11]) {
    if (len >= 2) {
        if (inequal[len - 2] == '<') {
            if (nums[len - 2] >= nums[len - 1])
                return 0;
        }
        else {
            if (nums[len - 2] <= nums[len - 1])
                return 0;
        }
    }
    return 1;
}

void f(int n, int len, int* used,  char(&nums)[11],
    char(&inequal)[11], std::vector<long long>& ans) {
    //check
    if (!check(len, nums,inequal)) {
        return;
    }
    if (len == n+1) {
        // 부등호와 부합하는지 확인

        //std::cout << nums << std::endl;
        
        long long tmp = 0;
        for (int i = 0; i < n+1; i++) {
            tmp *= 10;
            tmp += (nums[i]-48); //char to int
        }
        //std::cout << tmp << '\n';
        ans.push_back(tmp);
        
        return;
    }
    
    for (int i = 0; i <= 9; i++) {
        // int to char
        if (used[i]) {
            continue;
        }
        used[i] = 1;
        nums[len] = i+48;
        f(n, len + 1,used, nums, inequal, ans);
        used[i] = 0;
    }
}
int main() {
    int n;
    std::cin >> n;
    char inequal[11];
    char nums[11];
    int used[11] = {0};
    nums[n + 1] = '\0';
    for (int i = 0; i < n; i++) {
        std::cin >> inequal[i];
    }
    std::vector<long long> ans;

    f(n, 0,used, nums, inequal, ans);
    std::sort(ans.begin(), ans.end());

    std::cout << ans[ans.size()-1] << '\n';
    long long tmp = ans[0];
    if (tmp < pow(10, n)) {
        std::cout << "0";
    }
    std::cout << ans[0] << '\n';
    
    return 0;
}