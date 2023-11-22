#include <algorithm>
#include <gtest/gtest.h>
#include <vector>
using namespace std;
/// 5个状态：第一次不持有；第一次持有；第二次不持有；第二次持有；第三次不持有。
/// 其实第一次不持有的状态是不用记录的。
/// 注意初始化的时候，第一次持有和第二次持有都需要为-price[0]
class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(5, 0));
    dp[0][1] = -prices[0];
    dp[0][3] = -prices[0];
    for (int i = 1; i < n; ++i) {
      dp[i][0] = dp[i - 1][0];
      dp[i][1] = max(dp[i - 1][0] - prices[i], dp[i - 1][1]);
      dp[i][2] = max(dp[i - 1][1] + prices[i], dp[i - 1][2]);
      dp[i][3] = max(dp[i - 1][2] - prices[i], dp[i - 1][3]);
      dp[i][4] = max(dp[i - 1][3] + prices[i], dp[i - 1][4]);
    }
    return dp[n - 1][4];
  }
};

int main() {
  Solution s;
  vector<int> p1{1, 2, 3, 4, 5};
  EXPECT_EQ(s.maxProfit(p1), 4);
}