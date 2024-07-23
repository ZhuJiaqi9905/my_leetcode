// 删除子数组
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 10;
int n;
int k;
struct A {
  int f;
  int t;
};
A a[MAXN];
#define debug(x) cout << #x << " = " << x << endl
int getNum(int x, int n) {
  int ans = 0;
  while (x > 0) {
    if (x % n == 0) {
      x /= n;
      ans++;
    } else {
      break;
    }
  }
  return ans;
}
int main() {
  cin >> n >> k;
  int64_t total_f = 0;
  int64_t total_t = 0;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    a[i].t = getNum(x, 2);
    a[i].f = getNum(x, 5);
    total_t += a[i].t;
    total_f += a[i].f;
  }

  int l = 0;
  int r = 0;
  int fs = 0;
  int ts = 0;
  int64_t ans = 0;
  for (; l < n; ++l) {
    if (l > 0) {
      fs -= a[l - 1].f;
      ts -= a[l - 1].t;
    }
    while (r < n && (total_f - fs - a[r].f >= k) &&
           (total_t - ts - a[r].t >= k)) { // 这里要考虑a[r]本身
      fs += a[r].f;
      ts += a[r].t;
      r++;
    }
    ans += (r - l);
  }
  cout << ans << endl;
  return 0;
}