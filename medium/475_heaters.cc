#include <bits/stdc++.h>
using namespace std;
/// 排序+二分查找。
/// 感觉手写二分，从小到大排序的时候，还是找upper_bound比较好。
class Solution {
public:
  int findRadius(vector<int> &houses, vector<int> &heaters) {
    int ans = 0;
    int n = heaters.size();
    sort(heaters.begin(), heaters.end());
    for (const auto house : houses) {
      int idx = bin_search(house, heaters);
      int right = abs(heaters[idx] - house);
      int left = numeric_limits<int>().max();
      cout << house << " " << idx << endl;
      if (idx > 0) {
        left = abs(heaters[idx - 1] - house);
      }
      ans = max(min(left, right), ans);
    }
    return ans;
  }
  // 返回第一个比val大的元素。如果都比它大，就返回0。如果都比它小，返回最后的元素
  int bin_search(int val, const vector<int> &h) {
    int left = 0;
    int right = h.size() - 1;
    int mid = left + (right - left) / 2;
    while (left < right) {
      mid = left + (right - left) / 2;
      if (h[mid] < val) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }
    return left;
  }
};