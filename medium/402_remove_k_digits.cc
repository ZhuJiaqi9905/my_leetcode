#include <bits/stdc++.h>
using namespace std;
/// 贪心+单调栈。abcde，假设a,b,c,d单调递增，e违反了丹增条件，就往前删掉d,直到满足单增条件。
/// 类似题：316
class Solution {
public:
  string removeKdigits(string num, int k) {
    vector<char> stk;
    for (auto &digit : num) {
      // 单调递增的栈
      while (!stk.empty() && stk.back() > digit && k > 0) {
        stk.pop_back();
        k -= 1;
      }
      stk.push_back(digit);
    }
    for (; k > 0; --k) {
      stk.pop_back();
    }
    string ans = "";
    bool flag = false;
    for (auto &digit : stk) {
      if (!flag && digit == '0') {
        continue;
      }
      flag = true;
      ans += digit;
    }
    return ans == "" ? "0" : ans;
  }
};