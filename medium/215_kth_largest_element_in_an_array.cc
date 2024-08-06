#include <ctime>
#include <random>
#include <type_traits>
#include <vector>
using namespace std;

class Solution {
public:
  int quickSelect(vector<int> &a, int l, int r, int index) {
    int q = randomPartition(a, l, r);
    if (q == index) {
      return a[q];
    } else {
      return q < index ? quickSelect(a, q + 1, r, index)
                       : quickSelect(a, l, q - 1, index);
    }
  }

  inline int randomPartition(vector<int> &a, int l, int r) {
    int i = rand() % (r - l + 1) + l;
    swap(a[i], a[r]);
    return partition(a, l, r);
  }

  inline int partition(vector<int> &a, int l, int r) {
    int x = a[r], i = l - 1;
    for (int j = l; j < r; ++j) {
      if (a[j] <= x) {
        swap(a[++i], a[j]);
      }
    }
    swap(a[i + 1], a[r]);
    return i + 1;
  }

  int findKthLargest(vector<int> &nums, int k) {
    srand(time(0));
    return quickSelect(nums, 0, nums.size() - 1, nums.size() - k);
  }
};

class Solution3 {
public:
  void maxHeapify(vector<int> &a, int i, int heapSize) {
    int l = i * 2 + 1, r = i * 2 + 2, largest = i;
    if (l < heapSize && a[l] > a[largest]) {
      largest = l;
    }
    if (r < heapSize && a[r] > a[largest]) {
      largest = r;
    }
    if (largest != i) {
      swap(a[i], a[largest]);
      maxHeapify(a, largest, heapSize);
    }
  }

  void buildMaxHeap(vector<int> &a, int heapSize) {
    for (int i = heapSize / 2; i >= 0; --i) {
      maxHeapify(a, i, heapSize);
    }
  }

  int findKthLargest(vector<int> &nums, int k) {
    int heapSize = nums.size();
    buildMaxHeap(nums, heapSize);
    for (int i = nums.size() - 1; i >= nums.size() - k + 1; --i) {
      swap(nums[0], nums[i]);
      --heapSize;
      maxHeapify(nums, 0, heapSize);
    }
    return nums[0];
  }
};

class Solution4 {
public:
  int findKthLargest(vector<int> &nums, int k) {
    return search(nums, 0, nums.size() - 1, k);
  }
  int search(vector<int> &nums, int s, int e, int k) {
    if (s == e) {
      return nums[s];
    }
    int pivot = nums[s];

    int l = s;
    int r = e;
    while (l < r) {
      while (l < r && nums[r] < pivot) {
        r--;
      }
      if (l == r) {
        break;
      }
      swap(nums[r], nums[l]);
      l++;
      while (l < r &&
             nums[l] >
                 pivot) { // 这里不能用>=。有全是1点样例卡常数，会分的不均匀
        l++;
      }
      if (l == r) {
        break;
      }
      swap(nums[l], nums[r]);
      r--;
    }
    nums[l] = pivot;
    if ((l - s + 1) == k) {
      return nums[l];
    } else if ((l - s + 1) > k) {
      return search(nums, s, l - 1, k);
    } else {
      return search(nums, l + 1, e, k - (l - s + 1));
    }
  }
};