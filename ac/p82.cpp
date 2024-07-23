// 甜甜花酿鸡
#include <bits/stdc++.h>

using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  if (a > b) {
    swap(a, b);
  }
  if (b - a >= c) { // 如果a和b相差太大，就全给a
    cout << (a + c) / 2 << endl;
  } else {
    int y = (c + a - b) / 2;
    cout << (b + y) / 2 << endl;
  }

  return 0;
}