#include <cstdint>
#include <gtest/gtest.h>
#include <limits>
class Solution {
public:
  int reverse(int x) {
    int sign = 1;
    if (x == 0 || x == std::numeric_limits<int>().min()) {
      return 0;
    } else if (x < 0) {
      sign = -1;
      x = -x;
    }
    int64_t ans = 0;
    while (x > 0) {
      int num = x % 10;
      ans = ans * 10 + num;

      x = x / 10;
    }
    ans = ans * sign;
    if (ans > std::numeric_limits<int>().max() ||
        ans < std::numeric_limits<int>().min()) {
      return 0;
    } else {
      return ans;
    }
  }
};
int main() {
  Solution s;
  EXPECT_EQ(s.reverse(123), 321);
  EXPECT_EQ(s.reverse(-123), -321);
  EXPECT_EQ(s.reverse(120), 21);
  EXPECT_EQ(s.reverse(0), 0);
}