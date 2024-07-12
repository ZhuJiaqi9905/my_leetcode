// 树状数组模板题
#include <bits/stdc++.h>

using namespace std;

int n;
int m;

const int MAXN = 1e5 + 10;
int tr[MAXN];
inline int lowbit(int x) { return x & (-x); }

void update(int id, int val) {
  for (int i = id; i <= n; i += lowbit(i)) {
    tr[i] += val;
  }
}

int64_t getSum(int id) {
  int64_t s = 0;
  for (int i = id; i > 0; i -= lowbit(i)) {
    s += tr[i];
  }
  return s;
}

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    // 这里不能直接cin >> tr[i],而是要构建树状数组
    // cin >> tr[i];
    int v;
    cin >> v;
    update(i, v);
  }
  for (int i = 0; i < m; ++i) {
    int x, y, z;
    cin >> x >> y >> z;
    if (x == 1) {
      update(y, z);
    } else {
      cout << getSum(z) - getSum(y - 1) << endl;
    }
  }
  return 0;
}