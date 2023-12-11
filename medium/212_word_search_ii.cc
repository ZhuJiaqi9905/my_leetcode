#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
/// 字典树 + dfs， 但是一直在卡常数。
/// 一些优化技巧：
/// - Trie树的children从vector<Trie*>改为 unordered_map<char, Trie *> 
/// - end标记改成字符串本身
/// - 不另外使用vector<vector<bool>>来记录是否访问过该节点，而是直接修改board的值
/// - 进入dfs之前先判断需不需要进(边界，children非空)
/// - 对于a, aa, aaa, aaaa这种情况，a会被匹配好多次，因此对已经匹配过的word进行删除
/// - 如果你已经走到Trie树的叶子节点，就可以把它删除了。然后如果某个节点的所有叶子都被删除了，那么这个节点也可以被删除了
class Solution {
public:
  struct Trie {
    unordered_map<char, Trie *> children;
    string word{};
    Trie() {}
  };

  Trie root_;
  unordered_set<string> res_;
  int m_;
  int n_;

  vector<vector<int>> go_{{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
  void addWord(const string &word) {
    Trie *node = &root_;
    for (auto c : word) {
      if (!node->children.count(c)) {
        node->children[c] = new Trie();
      }
      node = node->children[c];
    }
    node->word = word;
  }

  vector<string> findWords(vector<vector<char>> &board, vector<string> &words) {
    for (auto &word : words) {
      addWord(word);
    }
    m_ = board.size();
    n_ = board[0].size();

    for (int i = 0; i < m_; ++i) {
      for (int j = 0; j < n_; ++j) {
        dfs(board, i, j, &root_);
      }
    }
    return std::vector<string>(res_.begin(), res_.end());
  }

  void dfs(vector<vector<char>> &board, int x, int y, Trie *node) {
    auto c = board[x][y];
    if (!node->children.count(c)) {
      return;
    }

    Trie *root = node;
    node = node->children[c];
    if (node->word.size() > 0) {
      res_.emplace(node->word);
      node->word = "";
    }
    if (!node->children.empty()) {
      board[x][y] = '#';
      for (int i = 0; i < 4; ++i) {
        int xx = x + go_[i][0];
        int yy = y + go_[i][1];
        if (xx >= 0 && xx < m_ && yy >= 0 && yy < n_ && board[xx][yy] != '#') {
          dfs(board, xx, yy, node);
        }
      }
      board[x][y] = c;
    }
    if (node->children.empty()) {
      root->children.erase(c);
    }
  }
};

int main() {}