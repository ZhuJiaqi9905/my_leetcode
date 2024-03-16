#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int maxMoves(vector<vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));

    for (int j = 1; j < n; ++j) {
      for (int i = 0; i < m; ++i) {
        // 三种更新情况。必须要保证上一个点是能够达到的，才会走到下一个
        // dp[i][j] = max(dp[i][j - 1], dp[i - 1][j - 1], dp[i + 1][j - 1])
        if (grid[i][j] > grid[i][j - 1] && (j == 1 || dp[i][j - 1] > 0)) {
          dp[i][j] = dp[i][j - 1] + 1;
        }
        if (i > 0 && grid[i][j] > grid[i - 1][j - 1] &&
            (j == 1 || dp[i - 1][j - 1] > 0)) {
          dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
        }
        if (i < (m - 1) && grid[i][j] > grid[i + 1][j - 1] &&
            (j == 1 || dp[i + 1][j - 1] > 0)) {
          dp[i][j] = max(dp[i][j], dp[i + 1][j - 1] + 1);
        }
      }
    }
    // for(int i = 0 ; i < m; ++i) {
    //     for(int j = 0; j  < n; ++j) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    int ans = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        ans = max(ans, dp[i][j]);
      }
    }
    return ans;
  }
};