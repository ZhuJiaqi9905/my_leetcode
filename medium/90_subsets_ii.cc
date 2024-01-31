#include <bits/stdc++.h>
using namespace std;
// 去重方法：先把集合排序，在枚举的时候判断：如果上一个元素和本元素相同，并且当前枚举的情况没有枚举上一个元素，那么这次的结果就会和之前的相同，就跳过它。
class Solution {
public:
  vector<vector<int>> subsetsWithDup(vector<int> &nums) {
    sort(nums.begin(), nums.end());

    int n = nums.size();
    uint64_t mask = (1LL << n) - 1;
    vector<vector<int>> ans;
    vector<int> tmp_ans;
    tmp_ans.reserve(n);
    for (uint64_t subset = 0; subset <= mask; subset++) {
      bool flag = true;
      for (uint32_t i = 0; i < n; ++i) {
        if (subset & (1 << i)) {
          if (i > 0 && (subset & (1 << (i - 1))) == 0 &&
              nums[i] == nums[i - 1]) {
            flag = false;
            break;
          }
          tmp_ans.emplace_back(nums[i]);
        }
      }
      if (flag) {
        ans.emplace_back(tmp_ans);
      }
      tmp_ans.clear();
    }
    return ans;
  }
};