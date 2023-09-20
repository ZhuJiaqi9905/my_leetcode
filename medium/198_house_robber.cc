#include <algorithm>
#include <cstddef>
#include <gtest/gtest.h>
#include <vector>
using namespace std;

/// dp[i][0]:表示截止到第i个房屋，不偷它的最大金额
/// dp[i][1]:表示截止到第i个房屋，偷它的最大金额
class Solution {
public:
  int rob(vector<int> &nums) {
    auto n = nums.size();
    vector<vector<int>> dp(n, vector<int>(2, 0));
    dp[0][1] = nums[0];
    for (size_t i = 1; i < n; ++i) {
      dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
      dp[i][1] = dp[i - 1][0] + nums[i];
    }
    return max(dp[n - 1][0], dp[n - 1][1]);
  }
};

void test(vector<int> &&nums, int ans) {
  Solution s;
  EXPECT_EQ(s.rob(nums), ans);
}
int main() {
  test(vector<int>{1, 2, 3, 1}, 4);
  test(vector<int>{2, 7, 9, 3, 1}, 12);
}