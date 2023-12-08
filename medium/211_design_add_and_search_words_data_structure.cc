#include <string>
#include <vector>
using namespace std;
/// Trie树+dfs
class WordDictionary {
public:
  vector<WordDictionary *> children_{vector<WordDictionary *>(26, nullptr)};
  bool end_{false};
  WordDictionary() {}

  void addWord(string word) {
    WordDictionary *node = this;
    for (auto c : word) {
      c -= 'a';
      if (node->children_[c] == nullptr) {
        node->children_[c] = new WordDictionary;
      }
      node = node->children_[c];
    }
    node->end_ = true;
  }

  bool search(string word) { return dfsSearch(this, word, 0, word.size()); }

  bool dfsSearch(WordDictionary *node, const string &word, int idx,
                 const int n) {

    for (int i = idx; i < n; ++i) {
      auto c = word[i];
      if (c != '.') {
        c -= 'a';
        if (node->children_[c] == nullptr) {
          return false;
        } else {
          node = node->children_[c];
        }
      } else {
        for (auto child : node->children_) {
          if (child == nullptr) {
            continue;
          }
          bool res = dfsSearch(child, word, i + 1, n);
          if (res == true) {
            return true;
          }
        }
        return false;
      }
    }
    return node->end_;
  }
};