#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  string getHint(string secret, string guess) {
    int n = secret.size();
    int bulls = 0;
    set<int> bull_pos;
    vector<int> chs(10, 0);
    int cows = 0;
    for (int i = 0; i < n; ++i) {
      if (secret[i] == guess[i]) {
        bulls++;
        bull_pos.insert(i);
      } else {
        chs[secret[i] - '0']++;
      }
    }
    for (int i = 0; i < n; ++i) {
      auto ch = guess[i];
      if (bull_pos.find(i) != bull_pos.end()) {
        continue;
      }
      int idx = guess[i] - '0';
      if (chs[idx] > 0) {
        chs[idx]--;
        cows++;
      }
    }
    return to_string(bulls) + "A" + to_string(cows) + "B";
  }
};
int main() {}