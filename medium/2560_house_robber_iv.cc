
#include <algorithm>
#include <gtest/gtest.h>
#include <vector>
using namespace std;

/// 题目中求最小化最大值问题，考虑用二分答案。

class Solution {
public:
  int minCapability(vector<int> &nums, int k) {
    auto res = minmax_element(nums.begin(), nums.end());
    auto lower = *res.first;
    auto upper = *res.second;
    while (lower < upper) {
      auto mid = (lower + upper) / 2;
      int count = 0;
      bool visit = false;
      for (const auto &x : nums) {
        if (x <= mid && !visit) {
          visit = true;
          count++;
        } else {
          visit = false;
        }
      }
      if (count >= k) {
        upper = mid;
      } else {
        lower = mid + 1;
      }
    }
    return lower;
  }

  vector<int> nums_;
  int k_;
  Solution(vector<int> &&nums, int k) : nums_(std::move(nums)), k_(k) {}

  int test() { return minCapability(nums_, k_); }
};

int main() { EXPECT_EQ(Solution(vector<int>{2, 3, 5, 9}, 2).test(), 5); }