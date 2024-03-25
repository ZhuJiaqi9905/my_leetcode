#include <bits/stdc++.h>
using namespace std;

int n, a, b;

bool check(int x) {
  int n1 = a / x;
  int n2 = b / x;
  if (n1 + n2 >= n) {
    return true;
  } else {
    return false;
  }
}
int solve() {
  int l = 1;
  int r = min(a, b);
  int mid = 0;

  while (l < r) {
    mid = (l + r + 1) / 2;
    if (check(mid)) {
      l = mid;
    } else {
      r = mid - 1;
    }
  }
  return l;
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    cin >> n >> a >> b;

    int ans = solve();
    cout << ans << endl;
  }
}
/*
2
5 2 3
1
4 7 10
3
*/