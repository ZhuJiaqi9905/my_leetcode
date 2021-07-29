/**
 * 用两个双边队列来维护滑动窗口中的最大值和最小值
 */
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
    int n = nums.size();
    deque<int> que_max;
    deque<int> que_min;
    int s = 0;
    int e = 0;
    int ans = 0;
    while (e < n) {
      while (!que_max.empty() && que_max.back() < nums[e]) {
        que_max.pop_back();
      }
      que_max.push_back(nums[e]);
      while (!que_min.empty() && que_min.back() > nums[e]) {
        que_min.pop_back();
      }
      que_min.push_back(nums[e]);
      while (!que_max.empty() && !que_min.empty() &&
             que_max.front() - que_min.front() > limit) {
        if (nums[s] == que_max.front()) {
          que_max.pop_front();
        }
        if (nums[s] == que_min.front()) {
          que_min.pop_front();
        }
        ++s;
      }
      ans = std::max(ans, e - s + 1);
      e++;
    }
    return ans;
    }
};