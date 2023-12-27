#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  vector<int> findSubstring(string &s, vector<string> &words) {
    vector<int> res;
    int m = words.size(), n = words[0].size(), ls = s.size();
    // i枚举可能的余数
    for (int i = 0; i < n && i + m * n <= ls; ++i) {
      // differ记录当前情况和目标情况的差异
      unordered_map<string, int> differ;
      // 得到窗口中前m个单词
      for (int j = 0; j < m; ++j) {
        ++differ[s.substr(i + j * n, n)];
      }
      for (string &word : words) {
        if (--differ[word] == 0) {
          differ.erase(word);
        }
      }
      for (int start = i; start < ls - m * n + 1; start += n) {
        if (start != i) { // 滑动窗口，排除初始构造出的differ
          string word = s.substr(start + (m - 1) * n, n);
          if (++differ[word] == 0) {
            differ.erase(word);
          }
          word = s.substr(start - n, n);
          if (--differ[word] == 0) {
            differ.erase(word);
          }
        }
        if (differ.empty()) {
          res.emplace_back(start);
        }
      }
    }
    return res;
  }
};
int main() {}