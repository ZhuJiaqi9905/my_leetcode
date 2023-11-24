#include <gtest/gtest.h>
class Solution {
public:
  double quickMul(double x, long long n) {
    double ans = 1;
    double x_contri = x;
    for (auto i = n; i > 0; i = (i >> 1)) {
      if ((i & 1) != 0) {
        ans *= x_contri;
      }
      x_contri *= x_contri;
    }
    return ans;
  }
  double myPow(double x, int n) {
    long long N = n;
    return N >= 0 ? quickMul(x, N) : 1 / quickMul(x, -N);
  }
};

int main() {
  Solution s;
  EXPECT_EQ(s.quickMul(2.0, 10), 1024);
}