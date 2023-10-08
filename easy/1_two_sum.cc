#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    unordered_map<int, int> umap;
    size_t n = nums.size();
    for (int i = 0; i < n; ++i) {
      auto it = umap.find(target - nums[i]);
      if (it != umap.end()) {
        return {i, umap[target - nums[i]]};
      }
      umap[nums[i]] = i;
    }
    return {};
  }
};
int main() {}