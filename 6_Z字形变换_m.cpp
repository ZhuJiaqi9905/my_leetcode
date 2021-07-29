class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1){
            return s;
        }
        int cycleLen = 2 * numRows - 2;
        int cyclen = (numRows + numRows - 2);
        int n = s.size();
        string ret;
        for(int i = 0; i < numRows; ++i){
            for(int j = 0; j + i < n; j += cyclen){
                ret += s[j + i];
                if(i != 0 && i != numRows - 1 && j +cyclen - i < n){
                    ret += s[j + cyclen - i];
                }
            }
        }
        return ret;
    }
};