#include <algorithm>
#include <vector>
using namespace std;
/// 贪心。以右端点从小到大排序。
class Solution {
public:
  int findMinArrowShots(vector<vector<int>> &points) {
    sort(
        points.begin(), points.end(),
        [](const vector<int> &u, const vector<int> &v) { return u[1] < v[1]; });
    int pos = points[0][1];
    int ans = 1;
    for (const auto &point : points) {
      if (point[0] > pos) {
        pos = point[1];
        ans++;
      }
    }
    return ans;
  }
};
int main() {}