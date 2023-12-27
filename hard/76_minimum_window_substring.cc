#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  string minWindow(string s, string t) {
    unordered_map<char, int> diff; // 最小覆盖子串必须满足diff[c] <= 0
    unordered_set<char> char_set;
    int diff_chars = 0; // 记录目前有差异的字符的数量。
    for (const auto &c : t) {
      diff[c] += 1;
      char_set.insert(c);
      diff_chars = char_set.size();
    }
    int n = s.size();
    int left = 0;
    int right = 0;
    string ans = "";
    for (; left <= n; ++left) {
      if (left != 0) {
        if (char_set.find(s[left - 1]) != char_set.end()) {
          if (++diff[s[left - 1]] == 1) {
            diff_chars += 1;
          }
        }
      }

      while (diff_chars != 0 && right < n) {
        const auto c = s[right];
        if (char_set.find(c) != char_set.end()) {
          diff[c] -= 1;
          if (diff[c] == 0) {
            diff_chars -= 1;
          }
        }
        right++;
      }
      if (diff_chars != 0) {
        break;
      }
      // 优化，去掉无用的冗余答案
      while (left < n) {
        if (char_set.find(s[left]) == char_set.end()) {
          left++;
        } else if (diff[s[left]] < 0) {
          diff[s[left]] += 1;
          left++;
        } else {
          break;
        }
      }

      if (right - left < ans.size() || ans == "") {
        cout << ans << endl;
        ans = s.substr(left, right - left);
      }
    }
    return ans;
  }
};
int main() {}