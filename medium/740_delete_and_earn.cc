#include <bits/stdc++.h>
using namespace std;
/// 转换为打家劫舍问题
class Solution {
public:
  int deleteAndEarn(vector<int> &nums) {
    int max_val = 0;
    for (int val : nums) {
      max_val = max(max_val, val);
    }
    vector<int> sum(max_val + 1, 0);
    // sum[i]是元素i的总点数
    for (int val : nums) {
      sum[val] += val;
    }
    return rob(sum);
  }
  /// dp[i][0]:表示截止到第i个房屋，不偷它的最大金额
  /// dp[i][1]:表示截止到第i个房屋，偷它的最大金额
  int rob(const vector<int> &nums) {
    auto n = nums.size();
    vector<vector<int>> dp(n, vector<int>(2, 0));
    dp[0][1] = nums[0];
    for (int i = 1; i < n; ++i) {
      dp[i][0] = max(dp[i - 1][1], dp[i - 1][0]);
      dp[i][1] = dp[i - 1][0] + nums[i];
    }
    return max(dp[n - 1][0], dp[n - 1][1]);
  }
};
int main() {}