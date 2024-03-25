#include<bits/stdc++.h>
using namespace std;
int n;
int k;
int a1;
int a2;
int a3;
int res;

int d[3];
int p[3];
void solve() {
    res = 0;
    p[0] = a1;
    p[1] = a2;
    p[2] = a3;
    sort(p, p + 3);
    if(3LL * k > n) {
        res = -1;
        return;
    }

    d[0] = p[1] - p[0];
    d[1] = p[2] - p[1];
    d[2] = p[0] + n - p[2];
    // 把最近的两个挪远
    sort(d, d + 3);
    
    while(d[0] < k) {
        int now = min(k - d[0], d[2] - k);
        res += now;
        d[2] -= now;
        d[0] += now;
        sort(d,  d+ 3);
    }


}
int main() {
    int t;
    cin >> t;
    while(t--) {
        cin >> n >> k >> a1 >> a2 >> a3;
        solve();
        cout << res << endl;
    }
    return 0;
}