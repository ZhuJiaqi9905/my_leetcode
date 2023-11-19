#include <gtest/gtest.h>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

/// dp[i]表示从s[0...i-1]的字符串能否被拆分。因为需要考虑到之前的字符串都不能被拆分，但是字典中有一个字符串完整匹配到的情况。
class Solution {
public:
  bool wordBreak(string s, vector<string> &wordDict) {
    auto word_dict = unordered_set<string>(wordDict.begin(), wordDict.end());
    int n = s.size();
    vector<int> dp(n + 1, 0);
    dp[0] = 1; // 这里一定是true。
    for (int i = 1; i <= n; ++i) {
      for (int j = 0; j < i; ++j) {
        if (dp[j] > 0 &&
            word_dict.find(s.substr(j, i - j)) != word_dict.end()) {
          dp[i] = 1;
          break;
        }
      }
    }
    return dp[n];
  }
};
int main() {
  Solution s;
  vector<string> wd1{"leet", "code"};
  EXPECT_EQ(s.wordBreak("leetcode", wd1), true);
}