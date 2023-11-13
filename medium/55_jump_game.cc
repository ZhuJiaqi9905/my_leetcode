#include <gtest/gtest.h>
#include <vector>
using namespace std;
class Solution {
public:
  bool canJump(vector<int> &nums) {
    int capacity = 0;
    int n = nums.size();
    if (n == 1) {
      return true;
    }
    capacity = nums[0];
    for (int i = 1; i < n; ++i) {
      if (capacity < i) {
        return false;
      }
      capacity = max(capacity, i + nums[i]);
    }
    return true;
  }
};

int main() {
  Solution s1;
  vector<int> n1{2, 3, 1, 1, 4};
  EXPECT_EQ(s1.canJump(n1), true);
  Solution s2;
  vector<int> n2{3, 2, 1, 0, 4};
  EXPECT_EQ(s2.canJump(n2), false);
}
