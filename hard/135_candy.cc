#include <gtest/gtest.h>
#include <iostream>
#include <map>
#include <numeric>
#include <vector>
using namespace std;
class Solution {
public:
  int candy(vector<int> &ratings) {
    int n = ratings.size();
    if (n == 1) {
      return 1;
    }
    vector<int> candys(n, 1);
    map<int, vector<int>> members;
    int min_rate = 2 * 1e4;
    for (int i = 0; i < n; ++i) {
      auto iter = members.find(ratings[i]);
      if (iter == members.end()) {
        members[ratings[i]] = vector<int>{i};
      } else {
        iter->second.push_back(i);
      }

      min_rate = min(min_rate, ratings[i]);
    }

    for (auto &kv : members) {
      if (kv.second.empty()) {
        continue;
      }
      auto &rate = kv.first;
      if (rate == min_rate) {
        continue;
      }
      for (auto &idx : kv.second) {
        if (idx == 0) {
          if (ratings[idx] > ratings[idx + 1]) {
            candys[idx] = candys[idx + 1] + 1;
          }
        } else if (idx == ratings.size() - 1) {
          if (ratings[idx] > ratings[idx - 1]) {
            candys[idx] = candys[idx - 1] + 1;
          }
        } else {
          if (ratings[idx] > ratings[idx + 1]) {
            candys[idx] = max(candys[idx], candys[idx + 1] + 1);
          }
          if (ratings[idx] > ratings[idx - 1]) {
            candys[idx] = max(candys[idx], candys[idx - 1] + 1);
          }
        }
      }
    }
    return accumulate(candys.begin(), candys.end(), 0);
  }

  int candy2(vector<int> &ratings) {
    int n = ratings.size();
    int ret = 1;
    int inc = 1;
    int dec = 0;
    int pre = 1;
    for (int i = 1; i < n; i++) {
      if (ratings[i] >= ratings[i - 1]) {
        dec = 0;
        pre = ratings[i] == ratings[i - 1] ? 1 : pre + 1;
        ret += pre;
        inc = pre;
      } else {
        dec++;
        if (dec == inc) {
          dec++;
        }
        ret += dec;
        pre = 1;
      }
    }
    return ret;
  }
};
int main() {
  Solution s;
  vector<int> r1{1, 0, 2};
  EXPECT_EQ(s.candy(r1), 5);

  vector<int> r2{1, 2, 2};
  EXPECT_EQ(s.candy(r2), 4);
}