// 前缀和
class NumArray {
private:
    vector<int> sums;
public:
    NumArray(vector<int>& nums) {
        sums.push_back(0);
        int sum = 0;
        for(auto& num: nums){
            sum += num;
            sums.push_back(sum);

        }
    }
    
    int sumRange(int i, int j) {
        return sums[j + 1] - sums[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */