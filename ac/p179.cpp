// 操作最小的k排列
#include <bits/stdc++.h>
using namespace std;

int n;
int k;
const int MAXN = 2e5 + 10;
int a[MAXN];

int main() {
  cin >> n >> k;

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<int> pos1;
  for (int i = 0; i < k; ++i) {
    if (a[i] > k) {
      pos1.push_back(i);
    }
  }
  vector<int> pos2;
  for (int i = k; i < n; ++i) {
    if (a[i] <= k) {
      pos2.push_back(i);
    }
  }
  int64_t ans = 0;
  for (int i = 0, s = pos1.size(); i < s; ++i) {
    ans += pos2[i] - pos1[i];
  }
  cout << ans << endl;
  return 0;
}