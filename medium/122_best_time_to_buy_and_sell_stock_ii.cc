#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  /// dp[i][0]: 在第i天，不持有股票状态的最大利润
  /// dp[i][1]: 在第i天，持有股票状态的最大利润
  int maxProfit(vector<int> &prices) {
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(2));
    dp[0][0] = 0;
    dp[0][1] = -prices[0];
    for (int i = 1; i < n; ++i) {
      dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
      dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
    }
    return dp[n - 1][0];
  }
};

int main() {
  Solution s1;
  vector<int> p1{7, 1, 5, 3, 6, 4};
  s1.maxProfit(p1);
}