// 切割绳子
#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
const int N = 1e5 + 10;
int a[N];
int n;

int64_t k;
int main() {

  int T;
  cin >> T;
  while (T--) {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    // 最小公倍数
    int c = a[0];
    for (int i = 1; i < n; ++i) {
      c = min(c, gcd(c, a[i]));
    }

    int64_t cnt = 0; // 要操作的次数
    for (int i = 0; i < n; ++i) {
      cnt += (a[i] / c) - 1;
    }
    if (cnt > k) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
    }
  }
  return 0;
}