// 最小公倍数
#include <bits/stdc++.h>
using namespace std;

int64_t gcd(int64_t x, int64_t y) { return y == 0 ? x : gcd(y, x % y); }

int main() {
  int x;
  int y;
  cin >> x >> y;
  cout << x / gcd(x, y) * y << endl;
  return 0;
}