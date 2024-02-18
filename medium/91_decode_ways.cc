#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int numDecodings(string s) {
    int n = s.size();
    vector<int> dp(n + 1, 0);
    if (s[0] == '0') {
      return 0;
    }
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 1; i < n; ++i) {
      if (s[i] == '0') {
        if (s[i - 1] != '1' && s[i - 1] != '2') {
          return 0;
        }
        dp[i + 1] = dp[i - 1];
      } else {
        if (s[i - 1] == '0') {
          dp[i + 1] = dp[i];
        } else {
          int num = (s[i - 1] - '0') * 10 + (s[i] - '0');
          cout << num << endl;
          if (num <= 26) {
            dp[i + 1] = dp[i] + dp[i - 1];
          } else {
            dp[i + 1] = dp[i];
          }
        }
      }
    }
    return dp[n];
  }
};
int main() {}