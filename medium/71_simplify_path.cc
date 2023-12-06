#include <string>
#include <vector>
using namespace std;

/// 用状态机来维护。可能会出现".....", "..hiden", "hiden..."这种文件名。
class Solution {
public:
  void reduceSlash(const string &path, int &idx, int n) {
    while (idx < n && path[idx] == '/') {
      idx++;
    }
  }

  string reduceDot(const string &path, int &idx, int n) {
    string res = "";
    while (idx < n && path[idx] != '/') {
      res += path[idx];
      idx++;
    }
    return res;
  }

  string getPathName(const string &path, int &idx, int n) {
    string res = "";
    while (idx < n && path[idx] != '/') {
      res += path[idx];
      idx++;
    }
    return res;
  }
  string simplifyPath(string path) {
    vector<string> stk;
    int idx = 0;
    int n = path.size();
    reduceSlash(path, idx, n);

    while (idx < n) {
      if (path[idx] == '/') {
        reduceSlash(path, idx, n);
      } else if (path[idx] == '.') {
        auto name = reduceDot(path, idx, n);
        if (name == "..") {
          if (!stk.empty()) {
            stk.pop_back();
          }
        } else if (name == ".") {
          continue;
        } else {
          stk.push_back(name);
        }
      } else {
        auto name = getPathName(path, idx, n);
        stk.push_back(name);
      }
    }
    string res = "/";
    int num = stk.size();
    if (num == 0) {
      return res;
    }
    for (int i = 0; i < num - 1; ++i) {
      res += stk[i];
      res += "/";
    }
    res += stk[num - 1];
    return res;
  }
};