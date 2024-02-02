#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  string reverseParentheses(string s) {
    stack<string> stk;
    string str;
    for (auto &ch : s) {
      if (ch == '(') {
        stk.push(str);
        str = "";
      } else if (ch == ')') {
        reverse(str.begin(), str.end());
        str = stk.top() + str;
        stk.pop();
      } else {
        str.push_back(ch);
      }
    }
    return str;
  }
};
/// 首先预处理记录左括号对应的右括号的位置，和右括号对应左括号的位置
/// 观察到如果当前位置的括号层数是奇数，答案就是从右到左遍历，如果括号层数是偶数，答案就是从左往右遍历
/// 所以预处理后就在括号之间横跳
class Solution2 {
public:
  string reverseParentheses(string s) {
    int n = s.size();
    vector<int> pair(n); // pair[i]记录与位置i配对的括号的位置
    stack<int> stk;
    for (int i = 0; i < n; ++i) {
      if (s[i] == '(') {
        stk.push(i);
      } else if (s[i] == ')') {
        int j = stk.top();
        stk.pop();
        pair[i] = j;
        pair[j] = i;
      }
    }
    string ans;
    int idx = 0;
    int step = 1;
    while (idx < n) {
      if (s[idx] == '(' || s[idx] == ')') {
        idx = pair[idx];
        step = -step;
      } else {
        ans += s[idx];
      }
      idx += step;
    }
    return ans;
  }
};
int main() {}