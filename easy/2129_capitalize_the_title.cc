#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  string capitalizeTitle(string title) {
    bool flag = false;
    string ans;
    int n = title.size();
    int i = 0;
    while (i < n) {
      while (i < n && title[i] == ' ') {
        i++;
      }
      int j = i;
      while (j < n && title[j] != ' ') {
        j++;
      }
      string word = title.substr(i, j - i);
      transform(word.begin(), word.end(), word.begin(), ::tolower);
      if (word.size() > 2) {
        word[0] = toupper(word[0]);
      }
      ans += word + " ";
      i = j;
    }
    ans.pop_back();
    return ans;
  }
};
int main() {}