// 最大维护成本
#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << #x << " = " << x << endl
const int MAXN = 2e5 + 10;
int f[MAXN][2]; // f[i][0]删除i节点能节省的成本。f[i][1]保留i节点能节省的成本。
int n;
int v[MAXN];

void dfs(int u) {
  int l = 2 * u;
  int r = 2 * u + 1;
  if (u > n || v[u] == 0) {
    return;
  }
  dfs(l);
  dfs(r);
  if (v[l] == 0 && v[r] == 0) {
    // leaf node
    f[u][1] = 0;
    f[u][0] = v[u];
    return;
  }

  f[u][0] = v[u] + f[l][1] + f[r][1];
  f[u][1] = max(f[l][0], f[l][1]) + max(f[r][0], f[r][1]);

  return;
}
int main() {
  cin >> n;
  int64_t sum = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> v[i];
    sum += v[i];
  }
  dfs(1);
  cout << max(f[1][0], f[1][1]) << endl;

  return 0;
}
