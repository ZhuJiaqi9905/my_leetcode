#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  vector<vector<int>> ans;
  vector<int> visit;
  vector<int> tmp_ans;
  int n;
  vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
    n = candidates.size();
    visit = vector<int>(n, 0);
    sort(candidates.begin(), candidates.end());
    dfs(candidates, target, 0);
    return ans;
  }

  void dfs(const vector<int> &candidates, int target, int idx) {
    if (target == 0) {
      ans.push_back(tmp_ans);
      return;
    }
    if (idx == n) {
      return;
    }
    if (candidates[idx] <= target &&
        !(idx > 0 && candidates[idx] == candidates[idx - 1] &&
          !visit[idx - 1])) {
      target -= candidates[idx];
      tmp_ans.push_back(candidates[idx]);
      visit[idx] = 1;
      idx += 1;
      dfs(candidates, target, idx);
      idx -= 1;
      visit[idx] = 0;
      target += candidates[idx];
      tmp_ans.pop_back();
    }

    dfs(candidates, target, idx + 1);
  }
};