#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int removeDuplicates(vector<int> &nums) {
    int idx = 0;
    int l = 0;
    int r = 0;
    int n = nums.size();
    while (r < n) {
      while (r < n && nums[r] == nums[l]) {
        r++;
      }
      nums[idx] = nums[l];
      idx++;
      l = r;
    }
    return idx;
  }
};