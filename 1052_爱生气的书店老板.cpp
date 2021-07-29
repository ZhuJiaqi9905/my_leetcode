class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int ans = 0;
        int basic = 0;//如果不抑制情绪，满意的顾客数量
        int n = customers.size();
        for(int i = 0; i < n; ++i){
            if(grumpy[i] == 0){
                basic += customers[i];
            }
        }
        //滑动窗口
        int s = 0; int e = X - 1;
        int slide = 0;//维护抑制情绪后的窗口中，满意的顾客的增加值
        int max_slide = 0;
        for(int i = 0; i <= e && i < n; ++i){
            if(grumpy[i] == 1){
                slide += customers[i];
            }
        }
        max_slide = slide;
        e++;
        while(e < n){
            if(grumpy[e] == 1){
                slide += customers[e];
            }
            if(grumpy[s] == 1){
                slide -= customers[s];
            }
            s++;
            e++;
            max_slide = std::max(max_slide, slide);
        }
        return basic + max_slide;
    }
};