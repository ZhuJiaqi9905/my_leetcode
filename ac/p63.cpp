// 价值二叉树
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1E5 + 10;
int n;

struct A {
  int64_t ts;
  int64_t fs;
};
A a[MAXN];
A v[MAXN];
vector<int> tr[MAXN];
int get_nums(int val, int x) {
  int res = 0;
  while (val > 0 && val % x == 0) {
    val /= x;
    res++;
  }
  return res;
}
void dfs(int u, int fa) {
  v[u].ts = a[u].ts;
  v[u].fs = a[u].fs;
  for (int x : tr[u]) {
    if (x == fa) {
      continue;
    }
    
    dfs(x, u);
    v[u].ts += v[x].ts;
    v[u].fs += v[x].fs;
  }
  return;
}
int main() {
  cin >> n;

  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    a[i].ts = get_nums(x, 2);
    a[i].fs = get_nums(x, 5);
  }
  for (int i = 1; i <= (n - 1); ++i) {
    int u;
    int v;
    cin >> u >> v;
    tr[u].push_back(v);
    tr[v].push_back(u);
  }

  dfs(1, 0);
  for (int i = 1; i <= n; ++i) {
    cout << min(v[i].ts, v[i].fs) << " ";
  }
  cout << endl;
}