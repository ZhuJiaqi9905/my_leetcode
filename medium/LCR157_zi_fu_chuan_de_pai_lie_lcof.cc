#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> visit;
  int n;
  vector<string> ans;
  vector<string> goodsOrder(string goods) {
    n = goods.size();
    sort(goods.begin(), goods.end());
    visit = vector<int>(n, 0);
    string tmp_ans;
    dfs(0, goods, tmp_ans);
    return ans;
  }
  void dfs(int k, const string &goods, string &tmp_ans) {
    if (k == n) {
      ans.emplace_back(tmp_ans);
      return;
    }
    for (int i = 0; i < n; ++i) {
      if (visit[i] || (i > 0 && !visit[i - 1] && goods[i - 1] == goods[i])) {
        continue;
      }
      visit[i] = 1;
      tmp_ans += goods[i];
      dfs(k + 1, goods, tmp_ans);
      tmp_ans.pop_back();
      visit[i] = 0;
    }
  }
};
int main() {}