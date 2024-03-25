#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL M = 1e7;

LL fastPow(LL x, int n) {
  int ans = 1;
  while (n > 0) {
    if (n & 1) {
      ans = ans * x % M;
    }
    x = x * x % M;
    n >>= 1;
  }
  return ans;
}
int main() {
  int n;
  cin >> n;

  LL ans = fastPow(2, n + 1) * (n - 1) % M;

  cout << ans << endl;
}