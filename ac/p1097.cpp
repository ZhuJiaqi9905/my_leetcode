#include <bits/stdc++.h>
#include <variant>
using namespace std;
// 打表发现到1~2e5中就有17984个质数。可以涵盖所有的人
const int N = 2e5;
const int MAXN = N + 10;
bool pr[MAXN];
bool vis[MAXN];
#define debug(x) cout << #x << " = " << x << endl
void get_primes() {
  pr[1] = true;
  for (int i = 2; i * i <= N; ++i) {
    if (!pr[i]) {
      for (int j = i * i; j <= N; j += i) {
        pr[j] = true;
      }
    }
  }
}

int main() {
  int n;
  cin >> n;
  get_primes();
  int cnt = n;
  int x = 1;
  while (cnt > 1) {
    for (int i = 1; i <= n; ++i) {
      if (vis[i]) {
        continue;
      }
      if (!pr[x]) { // 是质数
        vis[i] = true;
        cnt--;
        if (cnt == 1) {
          break;
        }
      }
      x++;
    }
  }
  for (int i = 1; i <= n; ++i) {
    if (!vis[i]) {
      cout << i << endl;
      break;
    }
  }
  return 0;
}