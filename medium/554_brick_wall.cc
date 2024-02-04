#include <bits/stdc++.h>
using namespace std;
// 前缀和+哈希表
class Solution {
public:
  int leastBricks(vector<vector<int>> &wall) {
    int n = wall.size();

    unordered_map<int, int> mp; // 每个位置对应的砖封数量
    for (int i = 0; i < n; ++i) {
      const auto &w = wall[i];
      int m = w.size();
      if (m == 1) {
        continue;
      }
      int sum = w[0];
      mp[sum] += 1;
      for (int j = 1; j < m - 1; ++j) {
        sum += w[j];
        mp[sum] += 1;
      }
    }
    int ans = 0;
    for (const auto &kv : mp) {
      ans = std::max(kv.second, ans);
    }
    ans = n - ans;
    return ans;
  }
};
int main() {}