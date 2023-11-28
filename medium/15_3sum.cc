#include <algorithm>
#include <vector>
using namespace std;
// 排序+双指针。枚举一个数，其余两个通过在排好序的数组中双指针移动，实现快速找到
class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    vector<vector<int>> ans;
    int n = nums.size();
    if (n < 3) {
      return ans;
    }
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n - 2; ++i) {
      // 去掉重复情况
      if (i > 0 && nums[i] == nums[i - 1]) {
        continue;
      }
      int left = i + 1;
      int right = n - 1;
      while (left < right) {
        int sum = nums[i] + nums[left] + nums[right];
        if (sum == 0) {
          if (!ans.empty()) {
            auto &last = ans[ans.size() - 1];
            if (last[0] != nums[i] || last[1] != nums[left]) {
              ans.push_back({nums[i], nums[left], nums[right]});
            }
          } else {
            ans.push_back({nums[i], nums[left], nums[right]});
          }
          ++left;
          --right;
        } else if (sum > 0) {
          --right;
        } else {
          ++left;
        }
      }
    }
    return ans;
  }
};

int main() {}