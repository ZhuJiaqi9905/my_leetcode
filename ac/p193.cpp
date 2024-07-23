// 货仓选址
#include <bits/stdc++.h>

using namespace std;

int n;
const int MAXN = 1e5 + 10;

int a[MAXN];
int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  sort(a, a + n);
  int x = a[n / 2];

  int64_t ans = 0;
  for (int i = 0; i < n; ++i) {
    ans += abs(x - a[i]);
  }
  cout << ans << endl;
  return 0;
}