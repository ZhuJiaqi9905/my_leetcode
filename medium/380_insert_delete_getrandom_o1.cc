#include <map>
#include <random>
#include <vector>
using namespace std;
class RandomizedSet {
public:
  vector<int> nums_;
  map<int, int> idxs_;
  RandomizedSet() {}

  bool insert(int val) {
    auto iter = idxs_.find(val);
    if (iter != idxs_.end()) {
      return false;
    }
    nums_.push_back(val);
    idxs_.emplace(val, nums_.size() - 1);
    return true;
  }
  /// 交换到尾部，再删除
  bool remove(int val) {
    auto iter = idxs_.find(val);
    if (iter == idxs_.end()) {
      return false;
    }
    int end_num = nums_[nums_.size() - 1];
    nums_[iter->second] = end_num;
    nums_.pop_back();
    idxs_[end_num] = iter->second;
    idxs_.erase(iter);
    return true;
  }

  int getRandom() { return nums_[rand() % nums_.size()]; }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
int main() {}