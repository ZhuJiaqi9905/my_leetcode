#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
  int minSubArrayLen(int target, vector<int> &nums) {
    int left = 0;
    int right = 0;
    int n = nums.size();
    int sum = 0;
    int ans = n + 1;
    while (right < n) {
      sum += nums[right];
      while (sum >= target) {
        ans = min(ans, right - left + 1);
        sum -= nums[left];
        left++;
      }
      right++;
    }
    return (ans == n + 1) ? 0 : ans;
  }
};
int main() {}