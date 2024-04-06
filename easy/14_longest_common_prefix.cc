#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  struct Node {
    Node *chs[26]{nullptr};
    bool e{false};
  };
  Node root;

  void insertStr(const string &str) {
    int n = str.size();
    Node *p = &root;
    for (int i = 0; i < n; ++i) {
      int c = str[i] - 'a';
      if (p->chs[c] == nullptr) {
        p->chs[c] = new Node;
      }
      p = p->chs[c];
    }
    p->e = true;
  }
  string longestCommonPrefix(vector<string> &strs) {
    for (const auto &str : strs) {
      insertStr(str);
    }
    string ans;
    Node *p = &root;
    while (true) {
      int cnt = 0;
      int idx = 0;
      if (p->e == true) {
        break;
      }
      for (int i = 0; i < 26; ++i) {
        if (p->chs[i] != nullptr) {
          cnt++;
          idx = i;
        }
      }
      if (cnt != 1) {
        break;
      }
      ans += 'a' + idx;
      p = p->chs[idx];
    }
    return ans;
  }
};
int main() {}