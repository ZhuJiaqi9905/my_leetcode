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
int main() {}