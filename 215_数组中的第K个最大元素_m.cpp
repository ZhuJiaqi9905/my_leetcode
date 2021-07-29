#include<vector>
using namespace std;

class Solution {
public:
    int quickSelect(vector<int>& a, int l, int r, int index) {
        int q = randomPartition(a, l, r);
        if (q == index) {
            return a[q];
        } else {
            return q < index ? quickSelect(a, q + 1, r, index) : quickSelect(a, l, q - 1, index);
        }
    }

    inline int randomPartition(vector<int>& a, int l, int r) {
        int i = rand() % (r - l + 1) + l;
        swap(a[i], a[r]);
        return partition(a, l, r);
    }

    inline int partition(vector<int>& a, int l, int r) {
        int x = a[r], i = l - 1;
        for (int j = l; j < r; ++j) {
            if (a[j] <= x) {
                swap(a[++i], a[j]);
            }
        }
        swap(a[i + 1], a[r]);
        return i + 1;
    }

    int findKthLargest(vector<int>& nums, int k) {
        srand(time(0));
        return quickSelect(nums, 0, nums.size() - 1, nums.size() - k);
    }
};


class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
      return search(nums, 0, nums.size() - 1, k);
    }
    int search(vector<int>& nums, int begin, int end, int k){
      if(begin == end){
        return nums[begin];
      }
      int tmp = nums[begin];
      int left = begin;
      int right = end;
      while(left < right){
        while(left < right && nums[right] < tmp){
          --right;
        }
        if(left == right){
          break;
        }
        nums[left] = nums[right];
        ++left;
        while (left < right && nums[left] >= tmp){
          ++left;
        }
        if(left == right){
          break;
        }
        nums[right] = nums[left];
        --right;
      }
      nums[left] = tmp;
      int idx = left - begin + 1;
      if(idx == k){
        return nums[left];
      }else if(idx > k){
        return search(nums, begin, left - 1, k);
      }else{
        return search(nums, left + 1, end, k - idx);
      }
    }
};