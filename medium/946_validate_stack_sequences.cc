#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool validateStackSequences(vector<int> &pushed, vector<int> &popped) {
    stack<int> st; // 用栈模拟
    size_t n = pushed.size();
    size_t j = 0;
    for (size_t i = 0; i < n; ++i) {
      st.push(pushed[i]); // 向栈中加入元素
      while (!st.empty() && j < n && st.top() == popped[j]) {
        ++j;
        st.pop();
      }
    }
    return st.empty();
  }
};
int main() {}