// 逆序对个数
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;

int w[MAXN];
int tr[MAXN];
int n;
inline int lowbit(int x) { return x & (-x); }

void update(int id, int val) {
  for (int i = id; i < MAXN; i += lowbit(i)) {
    tr[i] += val;
  }
}

int getSum(int id) {
  int ans = 0;
  for (int i = id; i > 0; i -= lowbit(i)) {
    ans += tr[i];
  }
  return ans;
}

int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> w[i];
  }
  int64_t ans = 0;
  for (int i = n - 1; i >= 0; --i) {
    ans += getSum(w[i] - 1);
    update(w[i], 1);
  }
  cout << ans << endl;
  return 0;
}