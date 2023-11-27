#include <unordered_map>
#include <vector>
using namespace std;
// Definition for a Node.
class Node {
public:
  int val;
  vector<Node *> neighbors;
  Node() {
    val = 0;
    neighbors = vector<Node *>();
  }
  Node(int _val) {
    val = _val;
    neighbors = vector<Node *>();
  }
  Node(int _val, vector<Node *> _neighbors) {
    val = _val;
    neighbors = _neighbors;
  }
};

class Solution {
public:
  unordered_map<Node *, Node *> visited;
  Node *cloneGraph(Node *node) {
    if (node == nullptr) {
      return node;
    }
    if (visited.find(node) != visited.end()) {
      return visited[node];
    }
    Node *new_node = new Node(node->val);
    visited[node] = new_node;

    for (auto &neigh : node->neighbors) {
      new_node->neighbors.push_back(cloneGraph(neigh));
    }

    return new_node;
  }
};

int main() {}