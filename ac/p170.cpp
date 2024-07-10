// 爬山模拟器
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;
int a[MAXN];
int b[MAXN];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }
  int64_t ans = 0;
  for (int i = 0; i < n; ++i) {
    ans += min(abs(a[i] + b[i]), abs(a[i] - b[i]));
  }
  cout << ans << endl;
}