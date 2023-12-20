#include <algorithm>
#include <bits/stdc++.h>
#include <iterator>

using namespace std;

class Solution {
public:
  vector<int> searchRange(vector<int> &nums, int target) {
    auto res = equal_range(nums.begin(), nums.end(), target);
    if (res.first == nums.end() || *res.first != target) {
      return {-1, -1};
    } else {
      int left = distance(nums.begin(), res.first);
      int right = distance(nums.begin(), res.second);
      return {left, right - 1};
    }
  }
};

int main() {}