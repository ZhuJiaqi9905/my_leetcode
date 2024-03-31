#include <bits/stdc++.h>
#include <iostream>
// 二分答案 + 树状数组
using namespace std;
const int MAXN = 100000 + 10;
int n;
#define debug(x) cout << #x << " = " << x << endl
// i从1开始
int a[MAXN];
int c[MAXN];
int c_init[MAXN];

int R;
int k;

inline int lowbit(int x) { return x & (-x); }

void updateTree(int id, int val) {
  while (id <= n) {
    c[id] += val;
    id += lowbit(id);
  }
}

int queryTree(int id) {
  int cnt = 0;
  while (id) {
    cnt += c[id];
    id -= lowbit(id);
  }
  return cnt;
}

int queryRange(int l, int r) { return queryTree(r) - queryTree(l - 1); }
void initTree() {
  for (int i = 1; i <= n; ++i) {
    updateTree(i, a[i]);
  }
  memcpy(c_init, c, sizeof(c));
}

bool check(int x) {
  // reset the c array
  memcpy(c, c_init, sizeof(c));
  int rest = k;
  for (int i = 1; i <= n; ++i) {
    int l = max(1, i - R);
    int r = min(n, i + R);
    int cur_sum = queryRange(l, r);
    if (cur_sum <= x) {
      if (rest >= x - cur_sum) {
        updateTree(r, x - cur_sum);
        rest -= x - cur_sum;
      } else {
        return false;
      }
    }
  }
  return true;
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  cin >> R;
  cin >> k;

  int l = 0;
  int r = 1000100000;
  initTree();

  while (l < r) {
    int mid = l + (r - l + 1) / 2;
    if (check(mid)) {
      l = mid;
    } else {
      r = mid - 1;
    }
  }
  cout << l << endl;
}

/*

4
4 4 4 4
0
3

4
*/

/*
5
1 2 4 5 0
1
2


5
*/