// 树的裁剪
// 注意这里输入的边不是有向的。所以要根据father做判断
#include <bits/stdc++.h>
#include <cstdint>
using namespace std;
const int MAXN = 1e5 + 10;

int a[MAXN];
int n;
int dep[MAXN];     // 每个点的深度
int64_t val[MAXN]; // 每个点及其子树的a[]的和
vector<int> tr[MAXN];
int64_t total_val = 0;
void dfs(int u, int d, int fa) {
  dep[u] = d;
  val[u] = a[u];
  total_val += 1ll * dep[u] * a[u];
  for (int x : tr[u]) {
    if (x == fa) {
      continue;
    }
    dfs(x, d + 1, u);
    val[u] += val[x];
  }
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  for (int i = 1; i <= (n - 1); ++i) {
    int u;
    int v;
    cin >> u >> v;
    tr[u].push_back(v);
    tr[v].push_back(u);
  }
  dfs(1, 1, 0);
  int64_t ans = total_val;
  for (int i = 2; i <= n; ++i) {
    ans = min(ans, total_val - (dep[i] - 2) * val[i]);
  }
  cout << ans << endl;
  return 0;
}