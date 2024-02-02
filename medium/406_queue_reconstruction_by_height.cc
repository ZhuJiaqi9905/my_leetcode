#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;
/// 从大到小排序，然后按照位置插入。因为身高矮的人不会影响到身高高的人的相对位置
class Solution {
public:
  vector<vector<int>> reconstructQueue(vector<vector<int>> &people) {
    sort(people.begin(), people.end(),
         [](const vector<int> &u, const vector<int> &v) {
           return u[0] > v[0] || (u[0] == v[0] && u[1] < v[1]);
         });
    vector<vector<int>> ans;
    for (const vector<int> &person : people) {
      ans.insert(ans.begin() + person[1], person);
    }
    return ans;
  }
};
int main() {}