#include<bits/stdc++.h>
// 组合数（一）
using namespace std;

int q;
int n;
int m;
const int64_t MOD = 1e9 + 7;
const int N = 1e3 + 10;

int64_t f[N][N];

int main() {
    cin >> q;
    f[0][0] = 1;
    for(int i = 1; i < N; ++i) {
        for(int j = 0; j <= i; ++j) {
            f[i][j] = f[i - 1][j] + f[i - 1][j - 1];
        }
    }
    while(q--) {
        cin >> n >> m;
        cout << f[n][m] << endl;
    }
}