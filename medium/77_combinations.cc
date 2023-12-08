#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> ans_;
  vector<vector<int>> combine(int n, int k) {
    vector<int> tmp_ans;
    dfs(0, n, k, tmp_ans);
    return ans_;
  }

  void dfs(int idx, int n, int k, vector<int> &tmp_ans) {
    if (idx == k) {
      ans_.emplace_back(tmp_ans);
      return;
    }
    int start = [&tmp_ans]() {
      if (tmp_ans.empty()) {
        return 1;
      } else {
        return tmp_ans.back() + 1;
      }
    }();
    for (int i = start; i <= n; ++i) {
      tmp_ans.emplace_back(i);
      dfs(idx + 1, n, k, tmp_ans);
      tmp_ans.pop_back();
    }
  }
};