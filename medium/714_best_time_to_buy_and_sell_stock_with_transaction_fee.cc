#include <cstddef>
#include <gtest/gtest.h>
#include <vector>
using namespace std;
/// dp[i][0]: 在第i天交易完毕后，没持有股票的状态下，最大利润
/// dp[i][1]: 在第i天交易完毕后，持有股票的状态下，最大利润
class Solution {
public:
  int maxProfit(vector<int> &prices, int fee) {
    vector<vector<int>> dp(prices.size(), vector<int>(2, 0));
    dp[0][0] = 0;
    dp[0][1] = -prices[0];
    auto n = prices.size();
    for (size_t i = 1; i < n; ++i) {
      dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i] - fee);
      dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
    }
    return dp[n - 1][0];
  }
};

int main() {
  Solution s1;
  vector<int> prices1 = {1, 3, 7, 5, 10, 3};
  EXPECT_EQ(s1.maxProfit(prices1, 3), 6);
}