#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int minEatingSpeed(vector<int> &piles, int h) {
    int low = 1;
    int high = *max_element(piles.begin(), piles.end());
    int k = high;
    while (low < high) {
      int mid = low + (high - low) / 2;
      int time = eat(piles, mid);
      if (time > h) {
        low = mid + 1;
      } else { // time <= h
        high = mid;
      }
    }
    return low;
  }
  int eat(const vector<int> &piles, int speed) {
    int time = 0;
    for (int pile : piles) {
      time += (pile + speed - 1) / speed;
    }
    return time;
  }
};