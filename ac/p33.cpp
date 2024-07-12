// 连通块个数
#include <bits/stdc++.h>
using namespace std;

int n;
int m;
const int MAXN = 210;
int p[MAXN];

void init() {
  for (int i = 0; i < n; ++i) {
    p[i] = i;
  }
}

int getRoot(int x) {
  if (x == p[x]) {
    return x;
  } else {
    p[x] = getRoot(p[x]);
    return p[x];
  }
}

void merge(int x, int y) {
  int rx = getRoot(x);
  int ry = getRoot(y);
  if (rx == ry) {
    return;
  }
  p[ry] = rx;
}

int main() {
  cin >> n >> m;
  init();
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    merge(u, v);
  }
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if (getRoot(i) == i) {
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}