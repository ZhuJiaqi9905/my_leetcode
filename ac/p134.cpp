#include<bits/stdc++.h>
using namespace std;
// 逆元
int64_t fpow(int64_t x, int64_t n, int64_t p) {
    int64_t ans = 1;
    while(n) {
        if(n & 1) {
            ans = ans * x % p;
        }
        x = x * x % p;
        n >>= 1;
    }
    return ans;
}
int main() {
    int64_t a;
    int64_t p;
    cin >> a >> p;
    cout << fpow(a, p - 2, p) << endl;
}