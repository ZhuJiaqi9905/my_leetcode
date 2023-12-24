#include <bits/stdc++.h>
using namespace std;
/// 翻转2次
class Solution {
public:
  void rotate(vector<vector<int>> &matrix) {
    int n = matrix.size();
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n - i; ++j) {

        swap(matrix[i][j], matrix[n - 1 - j][n - 1 - i]);
      }
    }

    int m = n / 2;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        swap(matrix[i][j], matrix[n - 1 - i][j]);
      }
    }
  }
};
int main() {}