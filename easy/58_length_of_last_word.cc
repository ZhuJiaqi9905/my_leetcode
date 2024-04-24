#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int lengthOfLastWord(string s) {
    int n = s.size();
    int r = -1;
    int l = 0;
    for (int i = n - 1; i >= 0; --i) {
      if (r == -1 && s[i] == ' ') {
        continue;
      } else if (r == -1) {
        r = i;
        continue;
      } else if (s[i] == ' ') {
        l = i + 1;
        break;
      }
    }

    return r - l + 1;
  }
};