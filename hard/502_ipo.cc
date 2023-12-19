#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int findMaximizedCapital(int k, int w, vector<int> &profits,
                           vector<int> &capital) {
    priority_queue<int, vector<int>, less<int>> pq;
    int n = profits.size();
    vector<pair<int, int>> arr;

    for (int i = 0; i < n; ++i) {
      arr.emplace_back(capital[i], profits[i]);
    }
    sort(arr.begin(), arr.end());
    int curr = 0;
    for (int i = 0; i < k; ++i) {
      while (curr < n && arr[curr].first <= w) {
        pq.emplace(arr[curr].second);
        curr++;
      }
      if (!pq.empty()) {
        w += pq.top();
        pq.pop();
      } else {
        break;
      }
    }
    return w;
  };
};