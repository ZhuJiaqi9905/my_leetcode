#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  void nextPermutation(vector<int> &nums) {
    int n = nums.size();
    if (n <= 1) {
      return;
    }
    int i = n - 2;
    int j = n - 1;
    int k = n - 1;
    for (; i >= 0 && nums[i] >= nums[j]; --i, --j) {
    }
    if (i >= 0) {
      while (nums[i] >= nums[k]) {
        k--;
      }
      swap(nums[i], nums[k]);
    }

    for (i = j, j = n - 1; i < j; ++i, --j) {
      swap(nums[i], nums[j]);
    }
  }
};