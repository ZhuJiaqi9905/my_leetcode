#include <bits/stdc++.h>
using namespace std;
/// 只有最内层的两数之和能转换为双指针
class Solution {
public:
  int n{0};
  vector<vector<int>> fourSum(vector<int> &nums, int target) {
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    n = nums.size();

    for (int a = 0; a < (n - 3); ++a) {

      if (nums[a] > target && nums[a] >= 0) {
        break;
      }
      if (a > 0 && nums[a] == nums[a - 1]) {
        continue;
      }
      long t1 = (long)target - nums[a];
      for (int b = a + 1; b < n - 2; ++b) {
        if (nums[b] > t1 && nums[b] >= 0) {
          break;
        }
        if (b > (a + 1) && nums[b] == nums[b - 1]) {
          continue;
        }
        long t2 = t1 - nums[b];

        int left = b + 1;
        int right = n - 1;
        while (left < right) {
          if (nums[right] + nums[left] > t2) {
            right--;
          } else if (nums[right] + nums[left] < t2) {
            left++;
          } else {
            res.push_back({nums[a], nums[b], nums[left], nums[right]});
            while (left < right && nums[left + 1] == nums[left]) {
              left++;
            }
            while (left < right && nums[right - 1] == nums[right]) {
              --right;
            }
            left++;
            right--;
          }
        }
      }
    }
    return res;
  }
};
int main() {}