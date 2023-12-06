#include <algorithm>
#include <iterator>
#include <vector>
using namespace std;

class Solution {
public:
  // 双指针
  vector<int> twoSum(vector<int> &numbers, int target) {
    int i = 0;
    int j = numbers.size() - 1;
    while (i < j) {
      int sum = numbers[i] + numbers[j];
      if (sum < target) {
        i++;
      } else if (sum > target) {
        j--;
      } else {
        return vector<int>{i + 1, j + 1};
      }
    }
    return vector<int>{-1, -1};
  }

  // 二分查找
  vector<int> twoSum2(vector<int> &numbers, int target) {
    vector<int> res;

    int n = numbers.size();
    for (int i = 0; i < n - 1; ++i) {
      auto it = lower_bound(numbers.begin() + i + 1, numbers.end(),
                            target - numbers[i]);
      if (it != numbers.end() && *it + numbers[i] == target) {
        res.push_back(i + 1);
        res.push_back(distance(numbers.begin(), it) + 1);
        return res;
      }
    }
    return res;
  }

  int binSearch(vector<int> &numbers, int left, int right, int target) {
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (numbers[mid] == target) {
        return mid;
      } else if (numbers[mid] > target) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
    return -1;
  }
};