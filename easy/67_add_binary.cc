#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  string addBinary(string a, string b) {
    if (a.size() < b.size()) {
      swap(a, b);
    }
    int n1 = a.size();
    int n2 = b.size();
    int carry = 0;
    for (int i = 1; i <= n1; ++i) {
      int a1 = a[n1 - i] - '0';
      int b1 = (n2 >= i) ? b[n2 - i] - '0' : 0;
      int res1 = (a1 + b1 + carry) % 2;
      carry = (a1 + b1 + carry) / 2;
      a[n1 - i] = '0' + res1;
    }
    if (carry != 0) {
      return "1"s + a;
    } else {
      return a;
    }
  }
};
int main() {}