class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty()) return 0;
        int i = 0; int j = 0;//双指针
        set<char> mySet;
        int n = s.size();
        int ans = 0;
        while(j < n){
            auto iter = mySet.find(s[j]);
            if(iter == mySet.end()){
                mySet.insert(s[j]);
                ans = max(ans, (int)mySet.size());
                j++;
            }
            else{
                mySet.erase(s[i]);
                i++;
            }
        }
        return ans;
    }
};