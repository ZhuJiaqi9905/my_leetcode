#include <bits/stdc++.h>
using namespace std;
/// 用差分+前缀和。
/// 原数组a[0...n)，差分数组d[0...n)。
/// 其中d[i]的含义是a[i]-a[i-1]。如果给a[l]到a[r]的所有元素都+n，相当于d[l]+=n并且d[r+1]-=n。
class Solution {
public:
  vector<int> corpFlightBookings(vector<vector<int>> &bookings, int n) {
    vector<int> nums(n, 0);
    for (auto &booking : bookings) {
      nums[booking[0] - 1] += booking[2];
      if (booking[1] < n) {
        nums[booking[1]] -= booking[2];
      }
    }
    for (int i = 1; i < n; i++) {
      nums[i] += nums[i - 1];
    }
    return nums;
  }
};