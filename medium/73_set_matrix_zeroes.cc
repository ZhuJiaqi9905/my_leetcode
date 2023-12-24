#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  void setZeroes(vector<vector<int>> &matrix) {
    unordered_set<int> rows;
    unordered_set<int> cols;
    int n = matrix.size();
    int m = matrix[0].size();
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (matrix[i][j] == 0) {
          rows.insert(i);
          cols.insert(j);
        }
      }
    }
    for (auto &row : rows) {
      for (int i = 0; i < m; ++i) {
        matrix[row][i] = 0;
      }
    }
    for (auto &col : cols) {

      for (int i = 0; i < n; ++i) {
        matrix[i][col] = 0;
      }
    }
  }
};
int main() {}