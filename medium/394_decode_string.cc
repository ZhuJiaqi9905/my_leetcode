#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution {
public:
  int read_num(const string &s, int &idx) {
    string str;
    while (isdigit(s[idx])) {
      str += s[idx];
      idx++;
    }
    return stoi(str);
  }
  int n_;
  string dfs(const string &s, int &idx) {
    string ans = "";
    while (idx < n_) {
      if (isdigit(s[idx])) {
        int num = read_num(s, idx);
        assert(s[idx] == '[');
        idx += 1;
        string sub_str = dfs(s, idx);
        // 此时idx是']'的下一个元素
        for (int i = 0; i < num; ++i) {
          ans += sub_str;
        }
      } else if (isalpha(s[idx])) {
        ans += s[idx];
      } else { // ']'
        idx += 1;
        return ans;
      }
    }
    return ans;
  }
  string decodeString(string s) {
    n_ = s.size();
    int idx = 0;
    return dfs(s, idx);
  }
};
int main() {
  Solution s1;
  string ss1 = "3[a]2[bc]";
  EXPECT_EQ(s1.decodeString(ss1), "aaabcbc");
}