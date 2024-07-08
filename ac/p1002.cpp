#include <bits/stdc++.h>

using namespace std;
using LL = long long;

int main() {
    int n; int k;
    cin >> n;
    cin >> k;
    unordered_set<int> m;
    LL a;
    for(int i = 0; i < n; ++i) {
        cin >> a;
        m.insert(a);
    }
    int ans = min(k,static_cast<int>( m.size()));
    cout << ans << endl;
    return 0;
}
