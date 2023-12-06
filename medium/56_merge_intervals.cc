#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>> &intervals) {
    vector<vector<int>> res;
    if (intervals.size() == 0) {
      return res;
    }
    // 按照从小到大排序
    sort(intervals.begin(), intervals.end());
    res.emplace_back(intervals[0]);
    for (int i = 1, n = intervals.size(); i < n; ++i) {
      auto &curr = res.back();
      if (intervals[i][0] > curr[1]) {
        res.emplace_back(intervals[i]);
      } else if (intervals[i][1] > curr[1]) {
        curr[1] = intervals[i][1];
      }
    }
    return res;
  }
};