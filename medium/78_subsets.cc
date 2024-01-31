#include <bits/stdc++.h>
using namespace std;
// 注意枚举子集的写法
class Solution {
public:
  vector<vector<int>> subsets(vector<int> &nums) {
    vector<vector<int>> ans;
    int n = nums.size();
    int mask = (1 << n) - 1;
    int subset = mask;
    do {
      vector<int> tmp_ans;
      for (int i = 0; i < n; ++i) {
        if ((subset & (1 << i)) != 0) {
          tmp_ans.push_back(nums[i]);
        }
      }
      ans.push_back(tmp_ans);
      // 枚举子集
      subset = (subset - 1) & mask;
    } while (subset != mask);
    return ans;
  }
};

// 用dfs也能做
class Solution2 {
public:
  int n_{0};
  vector<vector<int>> subsets(vector<int> &nums) {
    n_ = nums.size();
    vector<vector<int>> ans;
    vector<int> tmp_ans;
    tmp_ans.reserve(n_);
    dfs(nums, ans, 0, tmp_ans);
    return ans;
  }
  void dfs(const vector<int> &nums, vector<vector<int>> &ans, int k,
           vector<int> &tmp_ans) {
    if (k == n_) {
      ans.emplace_back(tmp_ans);
      return;
    }
    tmp_ans.emplace_back(nums[k]);
    dfs(nums, ans, k + 1, tmp_ans);
    tmp_ans.pop_back();
    dfs(nums, ans, k + 1, tmp_ans);
    return;
  }
};