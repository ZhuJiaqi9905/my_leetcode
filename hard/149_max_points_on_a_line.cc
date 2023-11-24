#include <algorithm>
#include <cmath>
#include <gtest/gtest.h>
#include <map>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;
/// 对每个点a, 计算剩余的点和点a连线的斜率。如果斜率相同就在一条直线上。
/// 注意斜率表示的正负号和约分。使用gcd函数。
/// 一些剪枝：枚举到点i时，最多（n -
/// i）个点共线；如果已经找到一条直线，通过了半数以上的点，那么它肯定是最终答案。
class Solution {
public:
  int maxPoints(vector<vector<int>> &points) {
    int n = points.size();
    if (n <= 2) {
      return n;
    }
    int ret = 0;
    for (int i = 0; i < n; ++i) {
      if (ret > n / 2 || ret >= (n - i)) {
        break;
      }
      map<pair<int, int>, int> mp;
      for (int j = i + 1; j < n; ++j) {
        auto &a = points[i];
        auto &b = points[j];
        auto dy = b[1] - a[1];
        auto dx = b[0] - a[0];
        if (0 == dy) {
          dx = 1;
        } else if (0 == dx) {
          dy = 1;
        } else {
          if (dy < 0) {
            dx = -dx;
            dy = -dy;
          }
          int gcd_xy = gcd(abs(dx), abs(dy));
          dx /= gcd_xy;
          dy /= gcd_xy;
        }
        mp[make_pair(dx, dy)]++;
      }
      auto max_ele = std::max_element(mp.begin(), mp.end(),
                                      [](const auto &lhs, const auto &rhs) {
                                        return lhs.second < rhs.second;
                                      });
      auto maxn = [&max_ele, &mp]() {
        if (max_ele == mp.end()) {
          return 1;
        } else {
          return max_ele->second + 1;
        }
      }();
      ret = max(ret, maxn);
    }
    return ret;
  }

  int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
};
int main() {
  Solution s;
  vector<vector<int>> p1{{1, 1}, {3, 2}, {5, 3}, {4, 1}, {2, 3}, {1, 4}};
  EXPECT_EQ(s.maxPoints(p1), 4);
}