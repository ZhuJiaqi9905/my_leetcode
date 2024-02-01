#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int countSubstrings(string s) {
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      dp[i][i] = 1;
      ans++;
      if (i < n - 1 && s[i] == s[i + 1]) {
        dp[i][i + 1] = 1;
        ans++;
      }
    }
    for (int k = 3; k <= n; ++k) {
      for (int i = 0; i < n; ++i) {
        int j = i + k - 1;
        if (j >= n) {
          break;
        }
        if (s[i] == s[j] && dp[i + 1][j - 1] == 1) {
          dp[i][j] = 1;
          ans++;
        }
      }
    }
    return ans;
  }
};
int main() {}