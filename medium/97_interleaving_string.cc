#include <deque>
#include <string>
using namespace std;

class Solution {
public:
  /// dp[i][j]表示用s1[0...i-1]和s2[0...j-1]两个字符串，能否交错构成s3[0...i+j-1]。
  /// 这种构造都要考虑s1或s2其中一个为空的情况，所以dp[0][0]为true。
  bool isInterleave(string s1, string s2, string s3) {
    int n = s1.size();
    int m = s2.size();
    int t = s3.size();
    if (n + m != t) {
      return false;
    }
    deque<deque<bool>> dp(n + 1, deque<bool>(m + 1, 0));

    dp[0][0] = true;
    for (int i = 0; i <= n; ++i) {
      for (int j = 0; j <= m; ++j) {
        int len = i + j - 1;
        if (i > 0) {
          dp[i][j] = dp[i][j] || (dp[i - 1][j] && s1[i - 1] == s3[len]);
        }
        if (j > 0) {
          dp[i][j] = dp[i][j] || (dp[i][j - 1] && s2[j - 1] == s3[len]);
        }
      }
    }
    return dp[n][m];
  }
};

int main() {}