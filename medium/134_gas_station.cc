#include <vector>
using namespace std;

/// 用图像平移的思想来解题。
class Solution {
public:
  int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
    int n = gas.size();
    // 相当于图像中的坐标点和最低点
    int sum = 0;
    int min_sum = 0;
    int start = 0;
    for (int i = 0; i < n; ++i) {
      sum += gas[i] - cost[i];
      if (min_sum > sum) {
        min_sum = sum;
        start = i + 1;
      }
    }
    if (sum < 0) {
      return -1;
    }
    return start % n;
  }
};
int main() {}