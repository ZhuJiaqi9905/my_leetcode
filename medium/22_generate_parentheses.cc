#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  vector<string> ans_;
  string tmp_ans_;

  vector<string> generateParenthesis(int n) {
    dfs(0, 0, n);
    return ans_;
  }

  void dfs(int left, int right, int n) {
    if (left == n && right == n) {
      ans_.push_back(tmp_ans_);
      return;
    }
    if (left < n) {
      tmp_ans_ += "(";
      dfs(left + 1, right, n);
      tmp_ans_.pop_back();
    }
    if (right < n && left > right) {
      tmp_ans_ += ")";
      dfs(left, right + 1, n);
      tmp_ans_.pop_back();
    }
  }
};
int main() {}