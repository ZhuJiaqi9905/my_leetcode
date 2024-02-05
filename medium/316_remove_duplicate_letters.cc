#include <bits/stdc++.h>
using namespace std;
/// 贪心+单调栈
/// 和402题一起看
class Solution {
public:
  string removeDuplicateLetters(string s) {
    unordered_map<char, int> mp; // 在当前ch的后面的子串中，每个字符还有几个
    vector<char> stk;      // 维护单调递增的栈
    vector<int> visit(26); // 记录这个字符是否已经在答案的序列中了
    for (const auto &ch : s) {
      mp[ch]++;
    }
    for (const auto &ch : s) {
      if (!visit[ch - 'a']) {
        while (!stk.empty() && stk.back() >= ch) {
          if (mp[stk.back()] >
              0) { // stk.back()字符后面还能出现，才可以在这里删除它
            visit[stk.back() - 'a'] = 0;
            stk.pop_back();
          } else {
            break;
          }
        }
        stk.push_back(ch);
        visit[ch - 'a'] = 1;
      }
      mp[ch]--;
    }

    return string(stk.begin(), stk.end());
  }
};