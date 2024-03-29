#include <gtest/gtest.h>
#include <iostream>
#include <pthread.h>
#include <stack>
#include <utility>
#include <vector>
using namespace std;
// 通常是一维数组，要寻找任一个元素的右边或者左边第一个比自己大或者小的元素的位置，此时我们就要想到可以用单调栈了
// 示例 1:

// 输入: temperatures = [73,74,75,71,69,72,76,73]
// 输出: [1,1,4,2,1,1,0,0]
// 示例 2:

// 输入: temperatures = [30,40,50,60]
// 输出: [1,1,1,0]
// 示例 3:

// 输入: temperatures = [30,60,90]
// 输出: [1,1,0]
class Solution {
public:
  vector<int> dailyTemperatures(vector<int> &temperatures) {
    int n = temperatures.size();
    stack<int> stack;
    vector<int> ans(n, 0);
    for (int i = 0; i < n; ++i) {
      auto t = temperatures[i];
      // 维护一个单调递减的栈
      while (!stack.empty() && t > temperatures[stack.top()]) {
        ans[stack.top()] = i - stack.top();
        stack.pop();
      }
      stack.push(i);
    }
    return ans;
  }
};
int main() {
  Solution s;
  //   auto ans = s.dailyTemperatures(temperatures);
  auto t1 = vector<int>{73, 74, 75, 71, 69, 72, 76, 73};
  auto a1 = vector<int>{1, 1, 4, 2, 1, 1, 0, 0};
  EXPECT_EQ(s.dailyTemperatures(t1), a1);

  auto t2 = vector<int>{30, 40, 50, 60};
  auto a2 = vector<int>{1, 1, 1, 0};
  EXPECT_EQ(s.dailyTemperatures(t2), a2);

  auto t3 = vector<int>{30, 60, 90};
  auto a3 = vector<int>{1, 1, 0};
  EXPECT_EQ(s.dailyTemperatures(t3), a3);
}