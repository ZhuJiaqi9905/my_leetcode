#include <bits/stdc++.h>
#include <gtest/gtest.h>

/// dp[i][j]表示由s[i...j]组成的子序列的最大回文子序列的长度。
/// 注意该题和第5题的区别
using namespace std;
class Solution {
public:
  int longestPalindromeSubseq(string s) {
    int n = s.size();
    if (n == 1) {
      return 1;
    }
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
      dp[i][i] = 1;
    }
    for (int i = 0; i < n - 1; ++i) {
      if (s[i] == s[i + 1]) {
        dp[i][i + 1] = 2;
      } else {
        dp[i][i + 1] = 1;
      }
    }
    for (int k = 3; k <= n; ++k) {
      for (int i = 0; i < n; ++i) {
        int j = i + k - 1;
        if (j >= n) {
          break;
        }
        if (s[i] == s[j]) {
          dp[i][j] = dp[i + 1][j - 1] + 2;
        } else { // 注意这里
          dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
        }
      }
    }
    return dp[0][n - 1];
  }
};
int main() {
  Solution s1;
  EXPECT_EQ(s1.longestPalindromeSubseq("bbbab"), 4);
}