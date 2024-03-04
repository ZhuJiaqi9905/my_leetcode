#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  struct Ele {
    int value;
    int label;
  };
  int largestValsFromLabels(vector<int> &values, vector<int> &labels,
                            int numWanted, int useLimit) {
    int n = values.size();
    vector<Ele> elements;
    elements.reserve(n);
    for (int i = 0; i < n; ++i) {
      elements.emplace_back(Ele{values[i], labels[i]});
    }
    sort(elements.begin(), elements.end(),
         [](const Ele &a, const Ele &b) { return a.value > b.value; });
    int ans = 0;
    int choose = 0;
    unordered_map<int, int> cnt;
    for (int i = 0; i < n && choose < numWanted; ++i) {
      int label = elements[i].label;
      if (cnt[label] == useLimit) {
        continue;
      }
      ++choose;
      ans += elements[i].value;
      ++cnt[label];
    }
    return ans;
  }
};
int main() {}