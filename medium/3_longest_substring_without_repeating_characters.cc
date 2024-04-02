#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    if (s.empty()) {
      return 0;
    }
    int i = 0;
    int j = 0;
    unordered_set<char> char_set;
    int n = s.size();
    int ans = 0;
    for (int j = 0; j < n; ++j) {
      while (char_set.find(s[j]) != char_set.end()) {
        char_set.erase(s[i]);
        i++;
      }
      char_set.emplace(s[j]);
      ans = max(ans, j - i + 1);
    }
    return ans;
  }
};
// 滑动窗口的另一种写法
class Solution2 {
public:
  int lengthOfLongestSubstring(string s) {
    int n = s.size();
    unordered_set<char> st;
    int l = 0;
    int r = 0;
    int ans = 0;
    for (l = 0; l < n; ++l) {
      if (l != 0) {
        st.erase(s[l - 1]);
      }
      while (r < n && st.find(s[r]) == st.end()) {
        st.insert(s[r]);
        r++;
      }

      ans = max(ans, r - l);
      if (r >= n) {
        break;
      }
      // 优化，一直删l的字符，直到和r的字符相同
      while (l < n) {
        if (s[l] != s[r]) {
          st.erase(s[l]);
          l++;
        } else {
          break;
        }
      }
      // cout << l << " " << r << endl;
    }
    return ans;
  }
};
int main() {}