#include <stdlib.h>
#include <string.h>
#include <string>
#include <unistd.h>
#include <vector>
using namespace std;
class Solution {
public:
  /// dp[i][j]是判断s[i...j]是否是回文串。如果是，存它的长度。如果不是，存0。
  string longestPalindrome(string s) {
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
      dp[i][i] = 1;
      if (i < n - 1 && s[i] == s[i + 1]) {
        dp[i][i + 1] = 2;
      }
    }
    for (int k = 3; k <= n; ++k) {
      // k是子串长度
      for (int i = 0; (i + k - 1) < n; ++i) {
        int j = i + k - 1;
        if (s[i] == s[j] && (dp[i + 1][j - 1] != 0 || k == 3)) {
          dp[i][j] = dp[i + 1][j - 1] + 2;
        }
      }
    }
    // 得到答案
    int maxL = 0;
    int maxi = 0;
    int maxj = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = i; j < n; ++j) {
        if (dp[i][j] > maxL) {
          maxL = dp[i][j];
          maxi = i;
          maxj = j;
        }
      }
    }
    return s.substr(maxi, maxj - maxi + 1);
  }
};
int main() {}