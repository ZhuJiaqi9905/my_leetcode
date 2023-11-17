#include <gtest/gtest.h>
#include <string>
using namespace std;
class Solution {
public:
  string reverseWords(string s) {
    string ans;
    // 把原字符串倒序了好处理
    reverse(s.begin(), s.end());
    int n = s.size();
    int i = 0;
    int start = 0;
    while (i < n) {
      while (s[i] == ' ' && i < n) {
        i++;
      }
      if (i == n) {
        break;
      }
      start = i;
      while (s[i] != ' ' && i < n) {
        i++;
      }
      // 如果需要原地替换，这里就用双指针
      string word = s.substr(start, i - start);
      reverse(word.begin(), word.end());
      ans += word;
      ans += ' ';
    }
    if (ans[ans.size() - 1] == ' ') {
      ans.pop_back();
    }
    return ans;
  }
};
int main() {
  Solution s;
  EXPECT_EQ(s.reverseWords("the sky is blue"), "blue is sky the");
  EXPECT_EQ(s.reverseWords("  hello world  "), "world hello");
  EXPECT_EQ(s.reverseWords("a good   example"), "example good a");
}