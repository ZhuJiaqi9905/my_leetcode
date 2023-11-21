#include <algorithm>
#include <gtest/gtest.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/// dp[i][j]是word1[0...i-1]转换成word2[0...j-1]的最少操作数
class Solution {
public:
  int minDistance(string word1, string word2) {
    int n = word1.length();
    int m = word2.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= m; ++i) {
      dp[0][i] = i;
    }
    for (int i = 1; i <= n; ++i) {
      dp[i][0] = i;
    }

    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        if (word1[i - 1] == word2[j - 1]) { // 注意这里是i-1和j-1
          dp[i][j] = dp[i - 1][j - 1];
        } else {
          dp[i][j] = dp[i - 1][j - 1] + 1;
        }
        dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
        dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
      }
    }

    return dp[n][m];
  }
};
int main() {
  Solution s1;
  s1.minDistance("horse", "ros");
}