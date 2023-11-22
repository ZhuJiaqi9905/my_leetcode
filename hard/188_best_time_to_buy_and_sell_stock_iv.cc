#include <vector>
using namespace std;

/// 类似第123题。k笔交易总共2k+1个状态，但是"从不持有“的状态是不用记录的
class Solution {
public:
  int maxProfit(int k, vector<int> &prices) {
    int n = prices.size();
    int m = 2 * k;
    vector<vector<int>> dp(n, vector<int>(m, 0));
    for (int i = 0; i < m; ++i) {
      if (i % 2 == 0) {
        dp[0][i] = -prices[0];
      }
    }
    for (int i = 1; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (j % 2 == 0) {
          if (j == 0) {
            dp[i][j] = max(-prices[i], dp[i - 1][j]);
          } else {

            dp[i][j] = max(dp[i - 1][j - 1] - prices[i], dp[i - 1][j]);
          }
        } else {
          dp[i][j] = max(dp[i - 1][j - 1] + prices[i], dp[i - 1][j]);
        }
      }
    }
    return dp[n - 1][m - 1];
  }
};

int main() {}