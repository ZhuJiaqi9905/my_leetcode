#include <vector>
using namespace std;
class Solution {
public:
  vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> mtx(n, vector<int>(n, 0));
    int left = 0;
    int right = n - 1;
    int up = 0;
    int down = n - 1;
    int val = 1;
    while (true) {
      for (int i = left; i <= right; ++i) {
        mtx[up][i] = val++;
      }
      if (left == right || up >= down) {
        break;
      }
      up++;
      for (int i = up; i <= down; ++i) {
        mtx[i][right] = val++;
      }
      right--;
      for (int i = right; i >= left; --i) {
        mtx[down][i] = val++;
      }
      down--;

      for (int i = down; i >= up; --i) {
        mtx[i][left] = val++;
      }
      left++;
    }
    return mtx;
  }
};

int main() {}