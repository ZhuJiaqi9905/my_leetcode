#include <string>
#include <vector>
using namespace std;
class Solution {
public:
  /// dp[i][j]表示s[0...i-1]和p[0...j-1]能否匹配
  bool isMatch(string s, string p) {
    int m = s.size();
    int n = p.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    dp[0][0] = 1;
    auto matches = [&](int i, int j) {
      if (i == 0) {
        return false;
      }
      if (p[j - 1] == '.') {
        return true;
      }
      return s[i - 1] == p[j - 1];
    };

    // 特殊处理dp[0][j]的情况
    for (int j = 2; j <= n; j += 2) {
      if (p[j - 1] == '*') {
        dp[0][j] = dp[0][j - 2];
      }
    }
    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (p[j - 1] == '*') {
          dp[i][j] |= dp[i][j - 2]; // 相当于abcx*中的x*出现0次
          if (s[i - 1] == p[j - 2] ||
              p[j - 2] == '.') { // 如果能够利用x*吃掉x,例如abcxx和abcx*
            dp[i][j] |= dp[i - 1][j];
          }
        } else if (p[j - 1] == '.') {
          dp[i][j] |= dp[i - 1][j - 1];
        } else if (p[j - 1] == s[i - 1]) {
          dp[i][j] |= dp[i - 1][j - 1];
        }
      }
    }

    return dp[m][n];
  }
};
int main(){}