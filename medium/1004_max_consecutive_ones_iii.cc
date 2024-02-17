#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int longestOnes(vector<int> &nums, int k) {
    int n = nums.size();
    int left = 0;
    int ans = 0;
    int right = 0;
    int zeros = 0;
    while (right < n) {
      while (right < n && zeros <= k) {
        if (nums[right] == 0) {
          zeros++;
        }
        right++;
      }
      if (right == n && zeros <= k) {
        ans = max(ans, right - left);
      } else {
        ans = max(ans, right - left - 1);
      }
      while (zeros > k) {
        if (nums[left] == 0) {
          zeros--;
        }
        left++;
      }
    }
    return ans;
  }
};