#include <vector>
#include <algorithm>
using namespace std;

// 排序+双指针。枚举一个数，其余两个通过在排好序的数组中双指针移动，实现快速找到
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int closest = nums[0] + nums[1] + nums[2];
        for(int i = 0; i < n - 2; ++i){//枚举nums[i]
            int left = i + 1;
            int right = n - 1;
            while(left < right){
                int three_sum = nums[left] + nums[right] + nums[i];
                if(abs(three_sum - target) < abs(closest - target)){
                    closest = three_sum;
                }
                if(three_sum > target){
                    --right;
                }else if(three_sum < target){
                    ++left;
                }else{
                    return three_sum;
                }
            }
        }
        return closest;
    }
};