#include <iostream>
#include <vector>
using namespace std;

/// dp[i][j]表示从(0,0)到(i, j)中，以(i, j)为定点的最大正方形边长
class Solution {
public:
  int maximalSquare(vector<vector<char>> &matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    int ans = 0;
    vector<vector<int>> dp(m, vector<int>(n, 0));
    if (matrix[0][0] == '1') {
      dp[0][0] = 1;
      ans = 1;
    }
    for (int i = 1; i < m; ++i) {
      if (matrix[i][0] == '1') {
        dp[i][0] = 1;
        ans = 1;
      }
    }
    for (int i = 1; i < n; ++i) {
      if (matrix[0][i] == '1') {
        dp[0][i] = 1;
        ans = 1;
      }
    }
    for (int i = 1; i < m; ++i) {
      for (int j = 1; j < n; ++j) {
        if (matrix[i][j] == '0') {
          continue;
        }
        int len = min(dp[i - 1][j], dp[i][j - 1]);
        if (matrix[i - len][j - len] == '1') {
          dp[i][j] = len + 1;
        } else {
          dp[i][j] = len;
        }
        ans = max(ans, dp[i][j]);
      }
    }

    // for (int i = 0; i < m; ++i) {
    //   for (int j = 0; j < n; ++j) {
    //     cout << dp[i][j] << " ";
    //   }
    //   cout << "\n";
    // }
    return ans * ans;
  }
};
int main() {
  Solution s;
  vector<vector<char>> m1{{'1', '0', '1', '0', '0'},
                          {'1', '0', '1', '1', '1'},
                          {'1', '1', '1', '1', '1'},
                          {'1', '0', '0', '1', '0'}};
  s.maximalSquare(m1);
}