#include <vector>
using namespace std;
class Solution {
public:
  vector<int> plusOne(vector<int> &digits) {

    int i = digits.size() - 1;
    while (true) {
      if (digits[i] < 9) {
        digits[i] += 1;
        return digits;
      }
      digits[i] = 0;
      if (i > 0) {
        i -= 1;
      } else if (i == 0) {
        break;
      }
    }
    digits = vector<int>(digits.size() + 1, 0);
    digits[0] = 1;
    return digits;
  }
};