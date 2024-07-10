// 最大子树和
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e4 + 10;
int n;
int v[MAXN];
vector<int> g[MAXN];
int f[MAXN];
int ans;
void dfs(int u, int fa) {
  f[u] = v[u];
  for (auto x : g[u]) {
    cout << "x " << x << endl;
    if (x == fa) {
      continue;
    }
    dfs(x, u);
    f[u] += max(0, f[x]);
  }
  ans = max(ans, f[u]);
  return;
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> v[i];
  }
  cout << 1 << endl;
  for (int i = 0; i < n - 1; ++i) {
    int a;
    int b;
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  cout << 2 << endl;
  dfs(1, -1);
  cout << ans << endl;
  return 0;
}