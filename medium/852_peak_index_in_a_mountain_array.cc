#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int peakIndexInMountainArray(vector<int> &arr) {
    int n = arr.size();
    int left = 0;
    // 注意这里是n-2，便于mid+1不越界
    int right = n - 2;

    while (left < right) {
      int mid = left + (right - left) / 2;
      if (arr[mid] > arr[mid + 1]) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }
    return left;
  }
};
int main(){}