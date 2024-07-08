#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;
int a[MAXN];
int dp[MAXN];

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    dp[0] = 1;
    int ans = 0;
    for(int i = 1; i < n; ++i) {
        if(a[i] > a[i - 1]) {
            dp[i] = dp[i - 1] + 1;
        }else {
            dp[i] = 1;
        }
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;

}