#include <gtest/gtest.h>
#include <iostream>
#include <vector>
using namespace std;

/// 注意[0]的特殊情况和边界值。
class Solution {
public:
  int jump(vector<int> &nums) {
    int n = nums.size();
    if (n == 1) {
      return 0;
    }
    int res = 0;
    int h = nums[0]; // 每次能跳到的极限位置
    int idx = 0;     // 每次用来更新最远位置的起始位置
    while (idx < n) {
      // 获取能跳跃的最大位置
      int max_h = 0;
      for (int i = idx; i < n && i <= h; ++i) {
        max_h = max(max_h, nums[i] + i);
      }
      idx = h + 1; // 因为之前<=h的位置都被更新过了
      h = max_h;
      res++;
    }
    return res;
  }
};

int main() {
  vector<int> n1{2, 3, 1, 1, 4};
  Solution s1;
  EXPECT_EQ(s1.jump(n1), 2);

  vector<int> n2{2, 3, 0, 1, 4};
  Solution s2;
  EXPECT_EQ(s2.jump(n2), 2);
}