#include <gtest/gtest.h>
#include <stack>
#include <vector>
using namespace std;
/// 从两边往里的双指针。这个题不用单调栈，它和第43题不同，它的墙没有厚度，也没有按块分割储水的问题。
class Solution {
public:
  int maxArea(vector<int> &height) {
    int n = height.size();
    int i = 0;
    int j = n - 1;
    int ans = 0;
    while (i < j) {
      int h = min(height[i], height[j]);
      ans = max(ans, h * (j - i));
      if (height[i] < height[j]) {
        ++i;
      } else {
        --j;
      }
    }
    return ans;
  }
};
int main() {
  Solution s;
  vector<int> h1{1, 8, 6, 2, 5, 4, 8, 3, 7};
  EXPECT_EQ(s.maxArea(h1), 49);
}