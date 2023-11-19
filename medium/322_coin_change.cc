#include <gtest/gtest.h>
#include <limits>
#include <set>
#include <vector>
using namespace std;
class Solution {
public:
  /// 这道题中每种类型的硬币可以用无限个。
  /// dp[i]表示凑出金额i的最少硬币个数.
  int coinChange(vector<int> &coins, int amount) {

    int n = coins.size();
    vector<int> dp(amount + 1, -1);
    dp[0] = 0;

    for (int i = 1; i <= amount; ++i) {
      for (int j = 0; j < n; ++j) {
        if (coins[j] <= i && dp[i - coins[j]] != -1) {
          if (dp[i] == -1) {
            dp[i] = dp[i - coins[j]] + 1;
          } else {
            dp[i] = min(dp[i], dp[i - coins[j]] + 1);
          }
        }
      }
    }
    return dp[amount];
  }
};
int main() {
  Solution s;
  vector<int> v1{1, 2, 5};
  EXPECT_EQ(s.coinChange(v1, 11), 3);

  vector<int> v2{2};
  EXPECT_EQ(s.coinChange(v2, 3), -1);

  vector<int> v3{1};
  EXPECT_EQ(s.coinChange(v3, 0), 0);
}