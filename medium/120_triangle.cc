#include <vector>

using namespace std;

class Solution {
public:
  int minimumTotal(vector<vector<int>> &triangle) {
    int n = triangle.size();
    if (n == 1) {
      return triangle[0][0];
    }
    vector<int> dp(n, 0);
    dp = triangle[n - 1];
    for (int i = n - 2; i >= 0; --i) {
      auto &nums = triangle[i];
      int m = nums.size();
      for (int j = 0; j < m; ++j) {
        dp[j] = nums[j] + min(dp[j], dp[j + 1]);
      }
    }
    return dp[0];
  }
};

int main() {}