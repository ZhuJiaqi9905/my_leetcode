#include <bits/stdc++.h>
using namespace std;

// 类似于“最大子数组和”。
// 定义dp[i]为以nums[i]为结尾的最大乘积子数组和。但是由于负负得正的原因，需要同时维护最大乘积子数组的值和最小乘积子数组的值。
// 所以用了dp_max和dp_min
class Solution {
public:
  int maxProduct(vector<int> &nums) {
    int n = nums.size();
    vector<int> dp_max(n, 0);
    vector<int> dp_min(n, 0);
    dp_max[0] = nums[0];
    dp_min[0] = nums[0];
    int ans = nums[0];
    for (int i = 1; i < n; ++i) {
      if (nums[i] == 0) {
        dp_max[i] = 0;
        dp_min[i] = 0;
      } else {
        dp_max[i] = max(dp_max[i - 1] * nums[i], nums[i]);
        dp_max[i] = max(dp_min[i - 1] * nums[i], dp_max[i]);
        dp_min[i] = min(dp_min[i - 1] * nums[i], nums[i]);
        dp_min[i] = min(dp_max[i - 1] * nums[i], dp_min[i]);
      }
      ans = max(ans, dp_max[i]);
    }
    return ans;
  }
};

int main() {}