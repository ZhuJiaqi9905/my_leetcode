#include <bits/stdc++.h>

using namespace std;
const int MAXN = 5e6 + 5;
int flag[MAXN];
int main() {
  int n;
  cin >> n;

  for (int i = 2; i * i <= n; ++i) {
    if (!flag[i]) {
      for (int j = i * i; j <= n; j += i) {
        flag[j] = 1;
      }
    }
  }
  int ans = 0;
  for (int i = 2; i <= n; ++i) {
    if (flag[i] == 0) {
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}