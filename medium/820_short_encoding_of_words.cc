#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;
class Node {
  Node *children_[26]{nullptr};

public:
  int cnt_{0}; // 用cnt_记录是否是其他单词的后缀
  Node *get(char c) {
    if (children_[c - 'a'] == nullptr) {
      children_[c - 'a'] = new Node();
      cnt_++;
    }
    return children_[c - 'a'];
  }
};
class Solution {
public:
  int minimumLengthEncoding(vector<string> &words) {
    Node trie;
    // 记录每一个tire树节点对应的单词的索引
    unordered_map<Node *, int> nodes;
    int n = words.size();
    for (int i = 0; i < n; ++i) {
      string &word = words[i];
      int m = word.size();
      Node *cur = &trie;
      for (int j = m - 1; j >= 0; --j) {
        cur = cur->get(word[j]);
      }
      nodes[cur] = i;
    }
    int ans = 0;
    for (auto &[node, idx] : nodes) {
      if (node->cnt_ == 0) { // 如果这个单词不是任何的其他单词的后缀
        ans += words[idx].length() + 1;
      }
    }
    return ans;
  }
};
int main() {}
