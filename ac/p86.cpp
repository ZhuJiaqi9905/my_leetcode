// 没有上司的舞会
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;
int r[MAXN];
vector<int> g[MAXN];
int f[MAXN][2];
int d[MAXN]; // 记录入度
void dfs(int u) {
  f[u][1] = r[u];
  for (int x : g[u]) {
    dfs(x);
    f[u][0] += max(f[x][0], f[x][1]);
    f[u][1] += f[x][0];
  }
}

int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) { // 注意编号从1开始
    cin >> r[i];
  }
  int l, k;
  for (int i = 0; i < n - 1; ++i) {
    cin >> l >> k;
    g[k].push_back(l);
    d[l]++;
  }
  int root = -1;
  for (int i = 1; i <= n; ++i) { // 注意编号从1开始
    if (d[i] == 0) {
      root = i;
      break;
    }
  }
  dfs(root);
  cout << max(f[root][0], f[root][1]) << endl;
  return 0;
}