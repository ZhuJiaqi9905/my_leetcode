// 循环节
#include <bits/stdc++.h>
using namespace std;

#define debug(x) cout << #x << " = " << x << endl
const int MAXN = 1e5 + 10;
unordered_map<char, int> mp; // 统计每个字符的出现次数

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
string s;
int main() {
  cin >> s;
  int n = s.size();
  for (int i = 0; i < n; ++i) {
    mp[s[i]] += 1;
  }

  int g = 0;
  for (auto it : mp) {
    int cnt = it.second;
    g = gcd(cnt, g); // 最大公约数
  }
  string res;
  // 生成循环节
  for (int i = 0; i < 26; ++i) {
    char ch = 'a' + i;
    if (mp.count(ch)) {
      res += string(mp[ch] / g, ch);
    }
  }

  string t = res;
  // debug(t);
  int k = s.size() / t.size();
  for (int i = 0; i < (k - 1); i++) {
    res += t;
  }
  cout << res << endl;
  return 0;
}