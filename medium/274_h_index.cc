#include "gtest/gtest.h"
#include <gtest/gtest.h>
#include <vector>
using namespace std;

/// 这个做法有点傻了
class Solution {

public:
  int hIndex(vector<int> &citations) {
    vector<int> scores(1001, 0);
    int max_cit = 0;
    for (const auto &c : citations) {
      scores[c]++;
      max_cit = max(max_cit, c);
    }
    for (int i = max_cit - 1; i >= 0; --i) {
      scores[i] = scores[i + 1] + scores[i];
    }
    return binSearchAns(scores, max_cit);
  }
  int binSearchAns(const vector<int> &scores, int max_cit) {
    int left = 0;
    int right = max_cit;
    while (left < right) {
      int mid = left + (right - left) / 2;
      if (scores[mid] < mid) {
        right = mid - 1;
      } else if (scores[mid] == mid) {
        return mid;
      } else {
        left = mid;
        if (right - left == 1) {
          if (scores[right] < right) {
            return left;
          } else {
            return right;
          }
        }
      }
    }
    return left;
  }
  ///用这个做法就行
  int hIndex2(vector<int> &citations) {
    sort(citations.begin(), citations.end());
    int h = 0, i = citations.size() - 1;
    ///假设h index的值是h
    while (i >= 0 && citations[i] > h) {
      h++;
      i--;
    }
    return h;
  }
};

int main() {
  //   Solution s1;
  //   vector<int> c1 = {3, 0, 6, 1, 5};
  //   EXPECT_EQ(s1.hIndex(c1), 3);

  //   Solution s2;
  //   vector<int> c2 = {1, 3, 1};
  //   EXPECT_EQ(s2.hIndex(c2), 1);

  Solution s3;
  vector<int> c3 = {1};
  EXPECT_EQ(s3.hIndex(c3), 1);
}