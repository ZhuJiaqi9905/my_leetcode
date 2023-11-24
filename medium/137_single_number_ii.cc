#include <gtest/gtest.h>
#include <vector>
using namespace std;

/// 分别考虑nums的每一位
class Solution {
public:
  int singleNumber(vector<int> &nums) {
    int a = 0, b = 0;
    for (int num : nums) {
      b = ~a & (b ^ num);
      a = ~b & (a ^ num);
    }
    return b;
  }
};
int main() {}