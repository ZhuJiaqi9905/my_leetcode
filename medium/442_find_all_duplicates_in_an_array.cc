#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;
class Solution {
public:
  vector<int> findDuplicates(vector<int> &nums) {
    int n = nums.size();
    unsigned int exist_bit = 1 << 30;
    unsigned int exist_mask = exist_bit - 1;
    unsigned int once_bit = 1 << 29;
    unsigned int once_mask = once_bit - 1;
    for (int i = 0; i < n; ++i) {

      int abs_num = nums[i] & once_mask;
      abs_num -= 1;
      if (nums[abs_num] & once_bit) {
        nums[abs_num] &= once_mask;
      } else {
        nums[abs_num] |= once_bit;
      }
      nums[abs_num] |= exist_bit;
    }
    vector<int> ans;
    for (int i = 0; i < n; ++i) {
      if ((nums[i] & once_bit) == 0 && (nums[i] & exist_bit)) {
        ans.emplace_back(i + 1);
      }
    }
    return ans;
  }
};
int main() {
  Solution s1;
  vector<int> n1 = {4, 3, 2, 7, 8, 2, 3, 1};
  vector<int> a1 = {2, 3};
  EXPECT_EQ(s1.findDuplicates(n1), a1);


  Solution s2;
  vector<int> n2 = {1,1,2};
  vector<int> a2 = {1};
  EXPECT_EQ(s2.findDuplicates(n2), a2);

  Solution s3;

}