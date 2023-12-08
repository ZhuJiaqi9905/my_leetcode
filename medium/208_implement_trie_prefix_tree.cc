#include <string>
#include <vector>
using namespace std;
class Trie {
public:
  vector<Trie *> children_;
  bool end_{false};
  Trie() : children_(26, nullptr) {}

  void insert(string word) {
    Trie *node = this;
    for (auto c : word) {
      c -= 'a';
      if (node->children_[c] == nullptr) {
        node->children_[c] = new Trie;
      }
      node = node->children_[c];
    }
    node->end_ = true;
  }

  bool search(string word) {
    Trie *node = this;
    for (auto c : word) {
      c -= 'a';
      if (node->children_[c] == nullptr) {
        return false;
      } else {
        node = node->children_[c];
      }
    }
    return node->end_;
  }

  bool startsWith(string prefix) {
    Trie *node = this;
    for (auto c : prefix) {
      c -= 'a';
      if (node->children_[c] == nullptr) {
        return false;
      } else {
        node = node->children_[c];
      }
    }
    return true;
  }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

int main() {
  Trie *obj = new Trie();
  obj->insert("apple"s);
  bool param_2 = obj->search("apple"s);
  bool param_3 = obj->startsWith("app"s);
}