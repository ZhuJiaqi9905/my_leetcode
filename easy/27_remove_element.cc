#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int removeElement(vector<int> &nums, int val) {
    int n = nums.size();
    if (n == 0) {
      return 0;
    }
    int l = 0;
    int r = n - 1;
    while (l < r) {
      while (l < r && nums[r] == val) {
        r--;
      }
      if (l == r) {
        break;
      }
      while (l < r && nums[l] != val) {
        l++;
      }
      if (l == r) {
        break;
      }
      swap(nums[l], nums[r]);
      l++;
      r--;
    }
    if (nums[l] != val) {
      return l + 1;
    } else {
      return l;
    }
  }
};