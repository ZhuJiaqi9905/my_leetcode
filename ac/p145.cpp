// 打游戏
#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1e5 + 10;
int h[MAXN];
int n;

int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> h[i];
    h[i] -= 1;
  }

  sort(h, h + n);
  // 排除已经死了的怪物
  int i = 0;
  while (h[i] == 0 && i < n) {
    i++;
  }

  int ans = 1 + 2 * (n - i); // 全用斩杀
  // 假设用旋风斩杀死了h[i],其余用斩杀
  for (; i < n; ++i) {
    int tmp_ans = 1 + h[i] + 2 * (n - i - 1);
    ans = min(ans, tmp_ans);
  }
  cout << ans << endl;
  return 0;
}
