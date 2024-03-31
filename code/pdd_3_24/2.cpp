#include <bits/stdc++.h>
using namespace std;
const int N = 5005;

char A[N], B[N];

map<string, int> mp;
int m;
int n;
#define debug(x) cout << #x << " = " << x << endl
int solve() {
  int ans = 0;
  for (int i = 0; i <= m - n; i++) {
    string st = "";
    int s0 = 0;
    int s1 = 0;
    // A[x+i] ^ B[i]
    for (int j = 0; j < n; j++) {
      if (A[i + j] == B[j]) {
        st += '0';
        s0++;
      } else {
        st += '1';
        s1++;
      }
    }
    if ((n & 1) == (s0 & 1)) {
      if (!mp[st]) {
        mp[st] = 1;
        ans++;
      }
    }
  }
  return ans;
}
int main() {
  cin >> m >> n;
  cin >> A >> B;
  int ans = solve();

  cout << ans << endl;
}

/*
8 2
10100000
10
*/