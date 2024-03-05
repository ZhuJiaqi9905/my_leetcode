#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    int m = matrix.size();
    int n = matrix[0].size();
    if (m == 1) {
      int x = binSearch(matrix[0], target);
      if (matrix[0][x] == target) {
        return true;
      } else {
        return false;
      }
    }
    vector v(m, 0);
    for (int i = 0; i < m; ++i) {
      v[i] = matrix[i][0];
    }
    int x = binSearch(v, target);
    if (v[x] == target) {
      return true;
    }
    if (x == 0) {
      return false;
    }
    if (v[x] > target) {
      x -= 1;
    }
    std::cout << "x: " << x << std::endl;
    for (int i = 0; i <= x; ++i) {
      int y = binSearch(matrix[i], target);
      if (matrix[i][y] == target) {
        return true;
      }
    }
    return false;
  }

  int binSearch(const vector<int> &v, int target) {
    if (v.size() == 0) {
      return -1;
    }
    int left = 0;
    int right = v.size() - 1;
    int mid = 0;
    while (left < right) {
      mid = left + (right - left) / 2;
      if (v[mid] == target) {
        return mid;
      } else if (v[mid] > target) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }
    return left;
  }
};

// Z字型查找
class Solution2 {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int x = 0, y = n - 1;
        while (x < m && y >= 0) {
            if (matrix[x][y] == target) {
                return true;
            }
            if (matrix[x][y] > target) {
                --y;
            }
            else {
                ++x;
            }
        }
        return false;
    }
};

