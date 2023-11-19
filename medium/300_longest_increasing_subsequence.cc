#include <algorithm>
#include <gtest/gtest.h>
#include <vector>
using namespace std;

class Solution {
public:
  /// dp[i]表示在nums[0...i]中，以nums[i]结尾所组成的最长递增子序列的长度。
  int lengthOfLIS(vector<int> &nums) {
    int n = nums.size();
    vector<int> dp(n, 1);
    for (int i = 1; i < n; ++i) {
      for (int j = 0; j < i; ++j) {
        if (nums[i] > nums[j]) {
          dp[i] = max(dp[i], dp[j] + 1);
        }
      }
    }
    return *max_element(dp.begin(), dp.end());
  }

  /// 贪心+二分查找
  /// tail[i]表示长度为i的递增子序列尾部元素的值。
  int lengthOfLIS2(vector<int> &nums) {
    int n = nums.size();
    if (n == 0) {
      return 0;
    }
    vector<int> tail(n + 1, 0);
    int len = 1;
    tail[len] = nums[0];

    for (int i = 1; i < n; ++i) {
      if (nums[i] > tail[len]) {
        tail[++len] = nums[i];
      } else {
        int left = 1;
        int right = len;
        /// 想找到tail[left]的位置，使得tail[left]是第一个满足 tail[left] >=
        /// nums[i]的位置，然后替换该位置的值
        while (left < right) {
          int mid = (left + right) / 2;
          if (tail[mid] < nums[i]) {
            left = mid + 1;
          } else if (tail[mid] > nums[i]) {
            right = mid;
          } else {
            left = mid;
            break;
          }
        }
        tail[left] = nums[i];
      }
    }
    return len;
  }
};

int main() {
  Solution s;

    vector<int> v1{10, 9, 2, 5, 3, 7, 101, 18};
    EXPECT_EQ(s.lengthOfLIS2(v1), 4);

    vector<int> v2{0, 1, 0, 3, 2, 3};
    EXPECT_EQ(s.lengthOfLIS2(v2), 4);

    vector<int> v3{7, 7, 7, 7, 7, 7, 7};
    EXPECT_EQ(s.lengthOfLIS2(v3), 1);

  vector<int> v4{3, 5, 6, 2, 5, 4, 19, 5, 6, 7, 12};
  EXPECT_EQ(s.lengthOfLIS2(v4), 6);
}