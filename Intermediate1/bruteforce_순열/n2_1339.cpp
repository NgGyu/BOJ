#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
char letter_to_number[256];
int calculate(vector<string>& operands
    , vector<char>& letters
    , vector<int>& numbers);
int main() {
    int n;
    cin >> n;
    vector<string> operands(n);
    vector<char> letters;
    vector<int> numbers;
    for (int i = 0; i < n; i++) {
        cin >> operands[i];
        for (char x : operands[i]) {
            letters.push_back(x);
        }
    }
    sort(letters.begin(), letters.end());
    letters.erase(
        unique(letters.begin(), letters.end())
        , letters.end());
    int sz = letters.size();
    for (int i = 9; i > 9 - sz; i--) {
        numbers.push_back(i);
    }
    int ans = 0;
    do {
        int now = calculate(operands, letters, numbers);
        if (ans < now) {
            ans = now;
        }
    } while (prev_permutation(numbers.begin(), numbers.end()));
    cout << ans;
    return 0;
}
int calculate(vector<string>& operands
    , vector<char>& letters
    , vector<int>& numbers)
{
    
    int m = letters.size();
    int sum = 0;
    for (int i = 0; i < m; i++) {
        letter_to_number[letters[i]] = numbers[i];
    }
    for (string s : operands) {
        int now = 0;
        
        for (char x : s) {
            now = now * 10 + letter_to_number[x];
        }
        sum += now;
    }
    return sum;
}
