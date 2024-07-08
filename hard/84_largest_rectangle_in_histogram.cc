#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int largestRectangleArea(vector<int> &heights) {
    stack<int> stk;
    int n = heights.size();
    vector<int> left(n), right(n);
    // 单调增的栈
    for (int i = 0; i < n; ++i) {
      while (!stk.empty() && heights[stk.top()] >= heights[i]) {
        stk.pop();
      }
      left[i] = stk.empty() ? -1 : stk.top();
      stk.push(i);
    }

    stk = stack<int>();

    for (int i = n - 1; i >= 0; --i) {
      while (!stk.empty() && heights[stk.top()] >= heights[i]) {
        stk.pop();
      }
      right[i] = stk.empty() ? n : stk.top();
      stk.push(i);
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      ans = max(ans, (right[i] - left[i] - 1) * heights[i]);
    }
    return ans;
  }
};