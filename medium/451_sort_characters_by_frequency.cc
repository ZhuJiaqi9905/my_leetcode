#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  string frequencySort(string s) {
    unordered_map<char, int> mp;
    for (auto ch : s) {
      mp[ch]++;
    }
    vector<pair<char, int>> vec;
    for (auto &it : mp) {
      vec.emplace_back(it.first, it.second);
    }
    sort(vec.begin(), vec.end(),
         [](const pair<char, int> &u, const pair<char, int> &v) {
           return u.second > v.second;
         });
    string res;
    for (const auto &kv : vec) {
      for (int i = 0; i < kv.second; ++i) {
        res += kv.first;
      }
    }
    return res;
  }
};
int main() {}