#include <cstddef>
#include <gtest/gtest.h>
#include <vector>
using namespace std;

/// dp[i][0]:表示截止到第i个房屋，不偷它的最大金额
/// dp[i][1]:表示截止到第i个房屋，偷它的最大金额
/// 成环的拆成两种情况，[0...n-1) 和[1...n)的最大值
class Solution {
public:
  int rob(vector<int> &nums) {
    auto size = nums.size();
    if (size == 1) {
      return nums[0];
    }
    auto ans1 = rob_line(nums.data(), size - 1);
    auto ans2 = rob_line(nums.data() + 1, size - 1);
    return max(ans1, ans2);
  }
  int rob_line(int *nums, size_t n) {

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
  test(vector<int>{2, 3, 2}, 3);
  test(vector<int>{1, 2, 3, 1}, 4);
  test(vector<int>{1, 2, 3}, 3);
}