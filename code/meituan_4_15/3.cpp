#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
int n;
const int MAX_NODES = 1e4;
int parent[MAX_NODES + 10];

void init() {
  for (int i = 1; i <= n; ++i) {
    parent[i] = i;
  }
}

int findRoot(int x) {
  if (parent[x] == x) {
    return x;
  }
  parent[x] = findRoot(parent[x]);
  return parent[x];
}

// 把x merge 给y
void mergeSet(int x, int y) {
  int px = findRoot(x);
  int py = findRoot(y);
  if (px == py) {
    return;
  }
  parent[px] = py;
}
int main() {
  cin >> n;
  int T;
  cin >> T;
  init();
  while (T--) {
    string op;
    int x;
    cin >> op >> x;
    if (op == "L") {
      if (x == 1) {
        continue;
      }
      mergeSet(x - 1, x);
    } else if (op == "R") {
      if (x == n) {
        continue;
      }
      mergeSet(x, x + 1);
    } else {
      int l = 1;
      int r = x;
      int px = findRoot(x);
      while (l < r) {
        int mid = (l + r) / 2;
        if (px == findRoot(mid)) {
          r = mid;
        } else {
          l = mid + 1;
        }
      }
      int ansl = l;

      l = x;
      r = n;
      while (l < r) {
        int mid = (l + r + 1) / 2;
        if (px == findRoot(mid)) {
          l = mid;
        } else {
          r = mid - 1;
        }
      }
      int ansr = r;
      cout << ansl << " " << ansr << endl;
    }
  }
}
/*
3 5
Q 2
L 2
Q 2
R 2
Q 2
*/