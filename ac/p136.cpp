#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int64_t MOD = 1e9 + 7;

int64_t fac[N];
int64_t ifac[N];
int64_t fpow(int64_t x, int64_t n) {
    int64_t ans = 1;
    while(n) {
        if(n & 1) {
            ans = ans * x % MOD;
        }
        x = x * x % MOD;
        n >>= 1;
    }
    return ans;
}

int main() {
    int q;
    cin >> q;
    int n, m;
    fac[0] = 1;
    ifac[0] = 1;
    for(int i = 1; i < N; ++i) {
        fac[i] = fac[i - 1] * i % MOD;
        ifac[i] = ifac[i - 1] * fpow(i, MOD-2) % MOD;
    }
    while(q--) {
        cin >> n >> m;
        cout << fac[n] * ifac[n - m] % MOD * ifac[m] % MOD << endl;
    }
    return 0;
}