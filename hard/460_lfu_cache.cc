#include <bits/stdc++.h>
using namespace std;
struct Node {
  int key, val, freq;
  Node(int _key, int _val, int _freq) : key(_key), val(_val), freq(_freq) {}
};
class LFUCache {
  int minfreq;
  int capacity;
  unordered_map<int, list<Node>::iterator> key_table; // key -> iter
  unordered_map<int, list<Node>> freq_table;          // freq -> list
public:
  LFUCache(int capacity) {
    minfreq = 0;
    this->capacity = capacity;
    key_table.clear();
    freq_table.clear();
  }

  int get(int key) {
    if (capacity == 0)
      return -1;
    auto it = key_table.find(key);
    if (it == key_table.end())
      return -1;
    list<Node>::iterator node = it->second;
    int val = node->val;
    int freq = node->freq;
    freq_table[freq].erase(node);
    if (freq_table[freq].size() == 0) {
      freq_table.erase(freq);
      if (minfreq == freq) {
        minfreq += 1;
      }
    }
    freq_table[freq + 1].push_front(Node(key, val, freq + 1));
    key_table[key] = freq_table[freq + 1].begin();
    return val;
  }

  void put(int key, int value) {
    if (capacity == 0)
      return;
    auto it = key_table.find(key);
    if (it == key_table.end()) {
      // 缓存已满，需要进行删除操作
      if (key_table.size() == capacity) {
        // 通过 minFreq 拿到 freq_table[minFreq] 链表的末尾节点
        auto it2 = freq_table[minfreq].back();
        key_table.erase(it2.key);
        freq_table[minfreq].pop_back();
        if (freq_table[minfreq].size() == 0) {
          freq_table.erase(minfreq);
        }
      }
      freq_table[1].push_front(Node(key, value, 1));
      key_table[key] = freq_table[1].begin();
      minfreq = 1;
    } else {
      auto node = it->second;
      int freq = node->freq;
      freq_table[freq].erase(node);
      if (freq_table[freq].size() == 0) {
        freq_table.erase(freq);
        if (minfreq == freq) {
          minfreq += 1;
        }
      }
      freq_table[freq + 1].push_front(Node(key, value, freq + 1));
      key_table[key] = freq_table[freq + 1].begin();
    }
  }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */