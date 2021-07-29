#include <queue>
#include <unordered_map>
using namespace std;
// 两个堆维护中位数 + 延迟删除
class DualHeap{
private:
  priority_queue<int> bigQ_;//大根堆，维护较小一半的元素. 如果k是奇数，大根堆多维护一个元素
  priority_queue<int, vector<int>, greater<int>> smallQ_; //小根堆，维护较大一半的元素
  unordered_map<int, int> delayed_;//记录延迟删除的元素。key为元素， value为需要删除的个数
  int k_;
  int small_size_{0};
  int big_size_{0};

  //不断弹出堆顶元素并更新哈希表
  template<typename T>
  void prune(T& heap){
    while(!heap.empty()){
      int ele = heap.top();
      if(delayed_.count(ele)){
        --delayed_[ele];
          if(!delayed_[ele]){
            delayed_.erase(ele);
          }
          heap.pop();
      }else{
        break;
      }
    }
  }
  void makeBalance(){
    if(big_size_ > small_size_ + 1){
      smallQ_.push(bigQ_.top());
      bigQ_.pop();
      --big_size_;
      ++small_size_;
      prune(bigQ_);
    }else if(big_size_ < small_size_){
      bigQ_.push(smallQ_.top());
      smallQ_.pop();
      ++big_size_;
      --small_size_;
      prune(smallQ_);
    }
  }
public:
  DualHeap(int k):k_(k){}
  double getMedian(){
    return k_ & 1 ? bigQ_.top() : ((double)bigQ_.top() + smallQ_.top()) / 2;
  }
  void insert(int num){
    if(bigQ_.empty() || num <= bigQ_.top()){
      bigQ_.push(num);
      ++big_size_;
    }else{
      smallQ_.push(num);
      ++small_size_;
    }
    makeBalance();
  }
  void erase(int num){
    ++delayed_[num];
    if(num <= bigQ_.top()){
      --big_size_;
      if(num == bigQ_.top()){
        prune(bigQ_);
      }
    }else{
      --small_size_;
      if(num == smallQ_.top()){
        prune(smallQ_);
      }
    }
    makeBalance();
  }
};

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        DualHeap dh(k);
        for (int i = 0; i < k; ++i) {
            dh.insert(nums[i]);
        }
        vector<double> ans = {dh.getMedian()};
        for (int i = k; i < nums.size(); ++i) {
            dh.insert(nums[i]);
            dh.erase(nums[i - k]);
            ans.push_back(dh.getMedian());
        }
        return ans;
    }
};
