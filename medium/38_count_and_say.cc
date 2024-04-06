#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  string countAndSay(int n) {
    if (n == 1) {
      return "1";
    }
    string s = countAndSay(n - 1);

    int l = s.size();
    int cnt = -1;
    char c;
    string ans;
    for (int i = 0; i < l; ++i) {
      if (cnt == -1) {
        c = s[i];
        cnt = 1;
        continue;
      }
      if (c == s[i]) {
        cnt++;
      } else {
        ans += to_string(cnt) + c;
        c = s[i];
        cnt = 1;
      }
    }
    ans += to_string(cnt) + c;
    return ans;
  }
};