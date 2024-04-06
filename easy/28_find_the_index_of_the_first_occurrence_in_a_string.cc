#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int strStr(string haystack, string needle) {
    int m = haystack.size();
    int n = needle.size();

    // next[i] = k, 意味着p[0...k-1] == p[i-k...i-1]
    vector<int> nxt(n, 0);

    // 构建next数组
    findNext(needle, nxt);

    // 匹配
    int i = 0; // pattern
    int j = 0; // target
    while (i < n && j < m) {
      if (i == -1 || needle[i] == haystack[j]) {
        i++;
        j++;
      } else {
        i = nxt[i];
      }
    }
    if (i >= n) {
      return j - n;
    } else {
      return -1;
    }
  }
  // 求模版串的next数组
  void findNext(const string &p, vector<int> &nxt) {
    nxt[0] = -1;
    int i = 0;
    int k = -1;
    int n = p.size();
    // 假设next[i]已经求好了，要求next[i + 1]
    while (i < n - 1) {
      while (k >= 0 && p[k] != p[i]) {
        k = nxt[k];
      }
      i++;
      k++;
      if (p[k] == p[i]) {
        nxt[i] = nxt[k];
      } else {
        nxt[i] = k;
      }
    }
  }
};