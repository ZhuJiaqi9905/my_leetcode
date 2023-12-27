#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  vector<int> findAnagrams(string s, string p) {
    unordered_map<char, int> need;
    unordered_map<char, int> window;
    for (const auto &c : p) {
      need[c] += 1;
    }
    int n = s.size();
    int left = 0;
    int right = 0;
    int valid = 0;
    vector<int> ans;
    while (right < n) {
      const char cur = s[right];
      right++;
      // 更新窗口数据
      if (need.find(cur) != need.end()) {
        window[cur] += 1;
        if (window[cur] == need[cur]) {
          valid++;
        }
      }
      // 判断左侧窗口是否要收缩。如果窗口中有无关的字符，就不满足（right-left ==
      // p.size()）的条件了
      while (right - left >= p.size()) {
        // 当窗口符合条件时，把起始索引加入 res
        if (valid == need.size())
          ans.push_back(left);
        char d = s[left];
        left++;
        // 进行窗口内数据的一系列更新
        if (need.count(d)) {
          if (window[d] == need[d])
            valid--;
          window[d]--;
        }
      }
    }

    return ans;
  }
};
int main() {}