
class Solution {
public:
  /// 求出公共前缀
  int rangeBitwiseAnd(int left, int right) {
    int shift = 0;
    while (left < right) {
      left >>= 1;
      right >>= 1;
      shift++;
    }
    return left << shift;
  }
};
int shift = 0;
