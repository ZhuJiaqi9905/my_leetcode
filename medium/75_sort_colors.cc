#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  void sortColors(vector<int> &nums) {
    int idx0 = 0;
    int idx1 = 0;
    int idx2 = 0;
    for (int i = 0, n = nums.size(); i < n; ++i) {
      if (nums[i] == 0) {
        nums[idx2++] = 2;
        nums[idx1++] = 1;
        nums[idx0++] = 0;
      } else if (nums[i] == 1) {
        nums[idx2++] = 2;
        nums[idx1++] = 1;
      } else {
        nums[idx2++] = 2;
      }
    }
  }
};