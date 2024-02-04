#include <bits/stdc++.h>
using namespace std;
// 贪心
class Solution {
public:
  string largestNumber(vector<int> &nums) {
    sort(nums.begin(), nums.end(), [](const int &a, const int &b) {
      return to_string(a) + to_string(b) > to_string(b) + to_string(a);
    });
    // 特判全0的情况
    if (nums[0] == 0) {
      return "0";
    }
    string ans;
    for (const auto &num : nums) {
      ans += to_string(num);
    }
    return ans;
  }
};
int main() {}