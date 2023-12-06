#include <unordered_map>
#include <vector>
using namespace std;
/// 很巧妙的动归。
class Solution {
public:
  int longestConsecutive(vector<int> &nums) {
    unordered_map<int, int> mp; // value为包含key的序列的最长长度
    int max_length = 0;
    for (auto num : nums) {
      if (mp.find(num) == mp.end()) {
        int left = [&mp, num]() {
          auto it = mp.find(num - 1);
          if (it == mp.end()) {
            return 0;
          } else {
            return it->second;
          }
        }();
        int right = [&mp, num]() {
          auto it = mp.find(num + 1);
          if (it == mp.end()) {
            return 0;
          } else {
            return it->second;
          }
        }();
        int cur_length = 1 + left + right;
        max_length = max(max_length, cur_length);
        mp[num] = cur_length;
        mp[num - left] = cur_length;
        mp[num + right] = cur_length;
      }
    }
    return max_length;
  }
};

int main() {}