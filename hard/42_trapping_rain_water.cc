#include <gtest/gtest.h>
#include <stack>
#include <vector>
using namespace std;
class Solution {
public:
  int trap(vector<int> &height) {
    int n = height.size();
    stack<int> stk;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      while (!stk.empty() && height[i] > height[stk.top()]) {
        int h = height[stk.top()];
        stk.pop();
        if (stk.empty()) {
          break;
        }
        // 横着算的
        int left = stk.top();
        int curr_width = i - left - 1;
        int curr_height = min(height[i], height[left]) - h;
        ans += curr_width * curr_height;
      }
      stk.push(i);
    }
    return ans;
  }
};

int main() {
  Solution s;
  vector<int> h1{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  EXPECT_EQ(s.trap(h1), 6);
}