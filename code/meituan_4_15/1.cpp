#include <bits/stdc++.h>
using namespace std;

string s;
string t;

int solve() {
    int ans = 0;
    int sn = s.size();
    int tn = t.size();
    int k = tn;
    if(sn > tn) {
        ans += sn - tn;
    } else {
        k = sn;
    }

    for(int i = 0; i < k; ++i) {
        if(s[i] != t[i]) {
            ans++;
        }
    }
    return ans;
}
int main() {
  int n;
  cin >> n;
  while (n--) {
    cin >> s;
    cin >> t;
    int ans = solve();
    cout << ans << endl;
  }
}

/*
2
aba
abb
abcd
efg
*/