#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int change(int amount, vector<int> &coins) {
    int n = coins.size();
    // dp[i][j]用前i种硬币凑出j元的组合数
    vector<vector<int>> dp(n, vector<int>(amount + 1, 0));
    for (int sum = 0; sum <= amount; sum += coins[0]) {
      dp[0][sum] = 1;
    }

    for (int i = 1; i < n; ++i) {
      // 这里可以解决5=5的情况。
      dp[i][0] = 1;
      for (int j = 1; j <= amount; ++j) {
        if (j >= coins[i]) {
          dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i]];
        } else {
          dp[i][j] = dp[i - 1][j];
        }
      }
    }
    return dp[n - 1][amount];
  }
};
int main() {}