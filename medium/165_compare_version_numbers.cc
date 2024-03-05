#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int compareVersion(string version1, string version2) {
    int n1 = version1.size();
    int n2 = version2.size();

    int idx1 = 0;
    int idx2 = 0;

    while (idx1 < n1 && idx2 < n2) {
      int v1 = get_num(version1, idx1);
      int v2 = get_num(version2, idx2);
      if (v1 > v2) {
        return 1;
      } else if (v1 < v2) {
        return -1;
      }
      if (idx1 == n1 && idx2 == n2) {
        return 0;
      }
      if (idx1 == n1) {
        idx2 += 1;
        while (idx2 < n2) {
          int v = get_num(version2, idx2);
          if (v > 0) {
            return -1;
          }
          idx2 += 1;
        }
        return 0;
      }
      if (idx2 == n2) {
        idx1 += 1;
        while (idx1 < n1) {
          int v = get_num(version1, idx1);
          if (v > 0) {
            return 1;
          }
          idx1 += 1;
        }
        return 0;
      }
      idx1++;
      idx2++;
    }
    return 0;
  }
  int get_num(const string &s, int &idx) {
    int n = s.size();
    int num = 0;
    while (idx < n) {
      if (s[idx] == '.') {
        break;
      }
      num = num * 10 + (s[idx] - '0');
      idx++;
    }
    return num;
  }
};
int main() {}