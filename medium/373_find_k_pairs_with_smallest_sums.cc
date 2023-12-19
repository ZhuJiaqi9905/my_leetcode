#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  bool flag = true; // 用来记录nums1和nums2是否交换了
  vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2,
                                     int k) {
    vector<vector<int>> ans;
    int n = nums1.size();
    int m = nums2.size();
    if (n > m) { // 让元素个数少的当nums1
      swap(nums1, nums2);
      swap(m, n);
      flag = false;
    }
    auto cmp = [&](const pair<int, int> &a, const pair<int, int> &b) {
      return nums1[a.first] + nums2[a.second] >
             nums1[b.first] + nums2[b.second];
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(
        cmp);
    for (int i = 0; i < min(n, k); i++) {
      pq.push({i, 0});
    }
    while (ans.size() < k && pq.size()) {
      auto [a, b] = pq.top();
      pq.pop();
      flag ? ans.push_back({nums1[a], nums2[b]})
           : ans.push_back({nums2[b], nums1[a]});
      if (b + 1 < m)
        pq.push({a, b + 1});
    }
    return ans;
  }
};