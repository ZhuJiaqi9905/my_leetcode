#include <cstddef>
#include <gtest/gtest.h>
#include <vector>
using namespace std;
/// 双指针

class Solution {
public:
  int removeDuplicates(vector<int> &nums) {
    size_t n = nums.size();
    if (n <= 2) {
      return n;
    }
    size_t lp = 0;
    size_t rp = 0;
    size_t idx = 0;
    while (true) {
      while (rp < n && nums[lp] == nums[rp]) {
        rp++;
      }
      if (rp - lp >= 2) {
        nums[idx++] = nums[lp];
        nums[idx++] = nums[lp];
      } else {
        nums[idx++] = nums[lp];
      }
      lp = rp;
      if (rp >= n) {
        break;
      }
    }
    return idx;
  }
};

int main() {
  Solution s1;
  vector<int> nums1 = {1, 1, 1, 2, 2, 3};
  vector<int> ans1 = {1, 1, 2, 2, 3};
  EXPECT_EQ(s1.removeDuplicates(nums1), 5);
  EXPECT_EQ(nums1, ans1);
}
