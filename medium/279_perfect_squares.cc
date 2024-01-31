#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int numSquares(int n) {
    int m = sqrt(n);
    vector<int> bag(0, m);
    for (int i = 1; i <= m; ++i) {
      bag.emplace_back(i * i);
    }

    vector<vector<int>> dp(m, vector<int>(n + 1, 0));
    for (int j = 1; j <= n; ++j) {
      dp[0][j] = j;
    }
    for (int i = 1; i < m; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (j >= bag[i]) {
          dp[i][j] = min(dp[i][j - bag[i]] + 1, dp[i - 1][j]);
        } else {
          dp[i][j] = dp[i - 1][j];
        }
      }
    }
    return dp[m - 1][n];
  }
};
int main() {}