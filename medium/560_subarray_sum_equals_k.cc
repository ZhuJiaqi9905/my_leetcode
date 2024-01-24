#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int subarraySum(vector<int> &nums, int k) {
    int ans = 0;
    int left = 0;
    int right = 0;
    int n = nums.size();
    vector<int> sum(n + 1, 0);          // sum[n] 是nums[0]到nums[n - 1]的和
    unordered_map<int, vector<int>> mp; // mp[i]是sum[k]==ii的所有k的位置
    mp.emplace(0, vector<int>{0});
    for (int i = 1; i <= n; ++i) {
      sum[i] = sum[i - 1] + nums[i - 1];
      if (mp.find(sum[i]) == mp.end()) {
        mp.emplace(sum[i], vector<int>{i});
      } else {
        mp[sum[i]].emplace_back(i);
      }
    }
    for (const auto &kv : mp) {
      if (mp.find(kv.first + k) == mp.end()) {
        continue;
      }
      const auto &vi = kv.second;
      const auto &vj = mp[kv.first + k];
      int len_j = vj.size();
      for (const auto &i : vi) {
        int idx = upper_bound(vj.begin(), vj.end(), i) - vj.begin();
        ans += len_j - idx;
      }
    }
    return ans;
  }
};
int main() {}