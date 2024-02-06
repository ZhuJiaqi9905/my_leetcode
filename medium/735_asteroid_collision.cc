#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
  vector<int> asteroidCollision(vector<int> &asteroids) {
    int n = asteroids.size();

    vector<int> ans;
    for (int i = 0; i < n; ++i) {
      if (asteroids[i] > 0) {
        ans.push_back(asteroids[i]);
      } else if (asteroids[i] < 0) {
        if (ans.empty() || ans.back() < 0) {
          ans.push_back(asteroids[i]);
          continue;
        }
        if (ans.back() > abs(asteroids[i])) {
          continue;
        } else if (ans.back() == abs(asteroids[i])) {
          ans.pop_back();
          continue;
        } else {
          bool equal = false;
          while (!ans.empty() && ans.back() > 0) {
            if (ans.back() < abs(asteroids[i])) {
              ans.pop_back();
            } else if (ans.back() == abs(asteroids[i])) {
              ans.pop_back();
              equal = true;
              break;
            } else {
              break;
            }
          }
          if (!equal && (ans.empty() || ans.back() < 0)) {
            ans.push_back(asteroids[i]);
          }
        }
      }
    }
    return ans;
  }
};