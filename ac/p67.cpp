// 频域二叉树
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 4096 + 10;

int mins[MAXN];
int maxs[MAXN];
int a[MAXN];
int n;
int64_t freq_tree[MAXN * 2];
// 类似线段树
void dfs(int u, int l, int r, int fa_sum) {
  if (u > 2 * n - 1) {
    return;
  }
  int min_val = 1e9, max_val = 0;
  for (int i = l; i <= r; i++) { // 求u的子节点中的最大值和最小值
    min_val = min(min_val, a[i]);
    max_val = max(max_val, a[i]);
  }
  freq_tree[u] = (min_val + max_val) / 2 - fa_sum;
  int mid = (l + r) / 2;
  dfs(u * 2, l, mid, fa_sum + freq_tree[u]);
  dfs(u * 2 + 1, mid + 1, r, fa_sum + freq_tree[u]);
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  dfs(1, 1, n, 0);
  for (int i = 1; i <= n * 2 - 1; i++)
    cout << freq_tree[i] << " ";
  return 0;
}