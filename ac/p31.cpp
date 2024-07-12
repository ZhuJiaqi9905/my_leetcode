// 亲戚
#include <bits/stdc++.h>
using namespace std;

int n;
int m;
int p_;

const int MAXN = 5000 + 10;
int p[MAXN];

void init() {
  for (int i = 0; i <= n; ++i) {
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
  int px = getRoot(x);
  int py = getRoot(y);
  if (px == py) {
    return;
  }
  p[py] = px;
}

int main() {
  cin >> n >> m >> p_;

  init();
  for (int i = 0; i < m; ++i) {
    int x, y;
    cin >> x >> y;
    merge(x, y);
  }

  for (int i = 0; i < p_; ++i) {
    int x, y;
    cin >> x >> y;
    if (getRoot(x) == getRoot(y)) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }
  return 0;
}