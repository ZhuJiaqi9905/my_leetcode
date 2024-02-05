#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  string crackPassword(vector<int> &password) {
    sort(password.begin(), password.end(), [](const int &u, const int &v) {
      return to_string(u) + to_string(v) < to_string(v) + to_string(u);
    });
    string ans;
    for (const auto w : password) {
      ans += to_string(w);
    }
    return ans;
  }
};