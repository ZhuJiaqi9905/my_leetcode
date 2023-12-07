#include <array>
#include <cstddef>
#include <string>
#include <vector>
using namespace std;

class Solution {
  array<string, 10> arr_{"",    "",    "abc",  "def", "ghi",
                         "jkl", "mno", "pqrs", "tuv", "wxyz"};

public:
  size_t n_;
  vector<string> ans_;
  vector<string> letterCombinations(string digits) {
    n_ = digits.size();
    if (n_ == 0) {
      return ans_;
    }

    string tmp_ans;
    dfs(digits, 0, tmp_ans);
    return ans_;
  }

  void dfs(const string &digits, int i, string &tmp_ans) {
    if (i == n_) {
      ans_.emplace_back(tmp_ans);
      return;
    }
    for (auto &c : arr_[digits[i] - '0']) {
      tmp_ans += c;
      dfs(digits, i + 1, tmp_ans);
      tmp_ans.pop_back();
    }
  }
};