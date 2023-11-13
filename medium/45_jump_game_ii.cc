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
    int cap = nums[0];
    int i = 0;
    int step = 1;
    if (cap >= n - 1) {
      return 1;
    }
    while (true) {
      int max_cap = cap;
      int idx = 0;
      for (; i <= cap; ++i) {
        if (nums[i] + i > max_cap) {
          max_cap = nums[i] + i;
          idx = i;
        }
      }
      cap = max_cap;
      i = idx;
      std::cout << max_cap << " " << i << endl;
      step++;
      if (cap >= n - 1) {
        break;
      }
    }
    return step;
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