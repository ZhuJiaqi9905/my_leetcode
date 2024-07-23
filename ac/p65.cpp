// 红绿二叉树
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;
vector<int> tr[MAXN];
int n;
int c[MAXN];

int64_t dfs(int u) {
  if (tr[u].size() == 0) {
    return 1;
  }
  if (tr[u].size() == 1) {
    return dfs(tr[u][0]);
  }
  int64_t l_val = dfs(tr[u][0]);
  int64_t r_val = dfs(tr[u][1]);
  if (c[u] == 1) {
    return l_val + r_val;
  } else {
    return l_val ^ r_val;
  }
}

int main() {

  cin >> n;
  for (int i = 2; i <= n; ++i) {
    int p;
    cin >> p;
    tr[p].push_back(i);
  }
  for (int i = 1; i <= n; ++i) {
    cin >> c[i];
  }

  int64_t ans = dfs(1);
  cout << ans << endl;
  return 0;
}