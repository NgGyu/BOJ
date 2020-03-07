//에라스토테네스의 체 이용
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
    int res = 0;
	//소인수분해 5의갯수
    cin >> n;
    //5의 배수갯수 + 5^2배수 갯수  + 5^3배수 갯수 + ....
    for(int i=5; i<=n;i*=5){
        res += n/i;
    }
    cout << res << "\n";

	return 0;
}