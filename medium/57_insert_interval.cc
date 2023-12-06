#include <algorithm>
#include <vector>
using namespace std;
// 遍历所有区间，看是否能取并集
class Solution {
public:
  vector<vector<int>> insert(vector<vector<int>> &intervals,
                             vector<int> &newInterval) {
    vector<vector<int>> res;
    int left = newInterval[0];
    int right = newInterval[1];
    bool flag = false;
    for (const auto &interval : intervals) {
      if (interval[1] < left) {
        res.emplace_back(interval);
      } else if (interval[0] > right) {
        if (!flag) {
          res.emplace_back(vector<int>{left, right});
          flag = true;
        }
        res.emplace_back(interval);
      } else { // 有交集，取并集
        left = min(left, interval[0]);
        right = max(right, interval[1]);
      }
    }
    if (!flag) {
      res.emplace_back(vector<int>{left, right});
    }
    return res;
  }
};