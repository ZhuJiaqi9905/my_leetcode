#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << #x << " = " << x << endl
const int MAXN = 1e5 + 10;
typedef long long LL;
LL a[MAXN];
int n;
int m;
int k;
int d;
// 删除和乘k肯定都是从最大的数开始的。就是看删除几个是最好的情况
LL solve() {
  sort(a + 1, a + 1 + n);
  int i = 0;
  // 前缀和的时候，数组从1开始
  for (int i = 1; i <= n; ++i) {
    a[i] = a[i - 1] + a[i];
  }

  LL ans = a[n - m] - (a[n] - a[n - m]) * k;
  debug(ans);
  for (int i = 1; i <= d; ++i) {
    ans = max(ans, a[n - i - m] - (a[n - i] - a[n - i - m]) * k);
  }
  return ans;
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    cin >> n >> m >> k >> d;
    for (int i = 1; i <= n; ++i) {
      cin >> a[i];
    }
    LL ans = solve();
    cout << ans << endl;
  }
  return 0;
}
/*
1
3 1 1 1
4 1 1

0
*/

/*
1
3 1 1 1
4 3 2

1
*/