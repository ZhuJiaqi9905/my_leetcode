#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;
class Solution {
public:
  /// 推数学。和最大公约数与最小公倍数有关
  void rotate(vector<int> &nums, int k) {
    int n = nums.size();
    k = k % n;
    int cnt = gcd(k, n);
    for (int i = 0; i < cnt; ++i) {
      int tmp = nums[i];
      int tid = i;
      int id = -1;
      while (true) {
        id = (tid + n - k) % n;
        if (id == i) {
          break;
        }
        nums[tid] = nums[id];
        tid = id;
      }
      nums[tid] = tmp;
    }
  }
};

int main() {}