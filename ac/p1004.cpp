#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define debug(x) cout << #x << " = " << x << endl
struct Info {
  int nt;
  int nf;
};
const int MAXN = 1e5 + 10;
int n;
int k;
Info a[MAXN];

int getMul(int n, int k) {
  int ans = 0;
  while (n % k == 0) {
    n /= k;
    ans++;
  }
  return ans;
}
int main() {
  cin >> n >> k;
  Info tot{0, 0};
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    a[i].nt = getMul(x, 2);
    a[i].nf = getMul(x, 5);

    tot.nt += a[i].nt;
    tot.nf += a[i].nf;
  }

  // 能删除的区间中最多有几个2和5
  Info m;
  m.nt = tot.nt - k;
  m.nf = tot.nf - k;
  if (m.nt < 0 || m.nf < 0) {
    return 0;
  }

  Info f{0, 0}; // 统计区间中的0的个数
  int e = 0;
  LL ans = 0;
  for (int s = 0; s < n; ++s) {
    if (s > 0) {
      f.nt -= a[s - 1].nt;
      f.nf -= a[s - 1].nf;
    }
    while (e < n && (f.nt + a[e].nt <= m.nt && f.nf + a[e].nf <= m.nf)) {
      f.nt += a[e].nt;
      f.nf += a[e].nf;

      e++;
    }

    ans += e - s;
  }
  cout << ans << endl;
  return 0;
}