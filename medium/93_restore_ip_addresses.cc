#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  vector<string> ans_;
  int n_;
  vector<string> restoreIpAddresses(string s) {
    n_ = s.size();
    string tmp_ans;
    dfs(s, 0, 0, tmp_ans);
    return ans_;
  }
  void dfs(const string &s, int idx, int level, string &tmp_ans) {
    if (level == 3) {
      int len = n_ - idx;
      if (s[idx] == '0' && len > 1) { // 有前导0
        return;
      }
      if (len > 3) {
        return;
      }
      string sub_str = s.substr(idx, len);
      if (stoi(sub_str) > 255) {
        return;
      }
      ans_.emplace_back(tmp_ans + sub_str);
      return;
    }

    for (int i = 1; i <= 3; ++i) {
      if (idx + i >= n_) {
        return;
      }
      if (s[idx] == '0' && i > 1) {
        return;
      }
      string sub_str = s.substr(idx, i);
      if (stoi(sub_str) > 255) {
        return;
      }
      int tmp_len = tmp_ans.size();

      tmp_ans += sub_str + ".";
      dfs(s, idx + i, level + 1, tmp_ans);
      tmp_ans.erase(tmp_len);
    }
  }
};

int main() {}