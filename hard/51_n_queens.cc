#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  vector<vector<string>> ans;
  vector<string> tmp_ans;
  bool col[10] = {false};
  bool lline[20] = {false};
  bool rline[20] = {false};
  vector<string> tem;
  int n;
  vector<vector<string>> solveNQueens(int n) {
    this->n = n;
    // generate template ans
    for (int i = 0; i < n; ++i) {
      string s;
      for (int j = 0; j < i; ++j) {
        s += '.';
      }
      s += 'Q';
      for (int j = i + 1; j < n; ++j) {
        s += '.';
      }
      tem.emplace_back(std::move(s));
    }

    dfs(0);
    return ans;
  }

  void dfs(int id) {
    if (id == n) {
      ans.push_back(tmp_ans);
      return;
    }
    // 尝试放第i列
    for (int i = 0; i < n; ++i) {
      if (!col[i] && !lline[n + i - id] && !rline[i + id]) {
        rline[i + id] = true;
        col[i] = true;
        lline[n + i - id] = true;
        tmp_ans.push_back(tem[i]);
        dfs(id + 1);
        tmp_ans.pop_back();
        rline[i + id] = false;
        col[i] = false;
        lline[n + i - id] = false;
      }
    }
  }
};