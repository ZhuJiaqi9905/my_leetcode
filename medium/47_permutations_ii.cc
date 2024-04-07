#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  vector<int> visit;
  int n;
  vector<vector<int>> ans;
  vector<int> tmp_ans;
  vector<vector<int>> permuteUnique(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    n = nums.size();
    visit = vector<int>(n, 0);

    dfs(nums, 0);
    return ans;
  }

  void dfs(const vector<int> &nums, int idx) {
    if (idx == n) {
      ans.push_back(tmp_ans);
      return;
    }
    for (int i = 0; i < n; ++i) {
      if (!visit[i] && !((i > 0) && nums[i] == nums[i - 1] && !visit[i - 1])) {
        tmp_ans.push_back(nums[i]);
        visit[i] = 1;
        dfs(nums, idx + 1);
        visit[i] = 0;
        tmp_ans.pop_back();
      }
    }
  }
};