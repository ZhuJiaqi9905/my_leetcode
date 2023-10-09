#include <gtest/gtest.h>
#include <string>
using namespace std;
/// 贪心。交替相加。
class Solution {
public:
  int splitNum(int num) {
    string snum = to_string(num);
    sort(snum.begin(), snum.end());
    int num1 = 0;
    int num2 = 0;
    int n = snum.length();
    for (int i = 0; i < n; ++i) {
      if (i % 2 == 0) {
        num1 = num1 * 10 + (snum[i] - '0');
      } else {
        num2 = num2 * 10 + (snum[i] - '0');
      }
    }
    return num1 + num2;
  }
};

int main() {
  Solution s1;
  EXPECT_EQ(s1.splitNum(4325), 59);
  EXPECT_EQ(s1.splitNum(687), 75);
}