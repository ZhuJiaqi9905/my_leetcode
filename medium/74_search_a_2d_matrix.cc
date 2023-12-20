#include <bits/stdc++.h>
using namespace std;
/// lower_bound, 返回第一个大于等于val的位置
/// upper_bound, 返回第一个大于val的位置
class Solution {
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    int m = matrix.size();
    int n = matrix[0].size();
    vector<int> arr(m, 0);
    for (int i = 0; i < m; ++i) {
      arr[i] = matrix[i][0];
    }
    auto it = upper_bound(arr.begin(), arr.end(), target);
    int idx = 0;
    if (it == arr.end()) {
      idx = m - 1;
    }
    if (it == arr.begin()) {
      return false;
    }
    it = it - 1;
    if (*it == target) {
      return true;
    }
    idx = distance(arr.begin(), it);

    cout << "idx: " << idx << endl;
    auto mat_it = lower_bound(matrix[idx].begin(), matrix[idx].end(), target);
    if (mat_it != matrix[idx].end() && *mat_it == target) {
      return true;
    } else {
      return false;
    }
  }
};
int main() {}