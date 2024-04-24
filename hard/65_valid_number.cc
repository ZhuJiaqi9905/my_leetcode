#include <bits/stdc++.h>
using namespace std;
// 写的很烂。完全是对着测试用例打补丁
class Solution {
public:
  bool isNumber(string s) {

    int n = s.size();
    int i;
    if (s[0] == '+' || s[0] == '-') {
      if (n == 1) {
        return false;
      }
      i = 1;
    } else {
      i = 0;
    }
    bool isE = false;
    bool isF = false;
    for (; i < n; ++i) {
      if (s[n - 1] == '+' || s[n - 1] == '-') {
        return false;
      }
      if ((s[i] == '+' || s[i] == '-') &&
          (s[i - 1] != 'e' && s[i - 1] != 'E')) {
        cout << "in here 1" << endl;
        return false;
      }
      if ((s[i] == '+' || s[i] == '-') &&
          (s[i - 1] == 'e' || s[i - 1] == 'E')) {
        cout << "in here 2" << endl;
        continue;
      }
      if (s[i] == '.') {
        if (!((i > 0 && isdigit(s[i - 1])) ||
              (i < n - 1 && isdigit(s[i + 1])))) {
          return false;
        }
        if (isE) {
          return false;
        }
        if (isF) {
          return false;
        }
        isF = true;
        continue;
      }
      if (s[i] == 'e' || s[i] == 'E') {
        if (!(i < n - 1 &&
              (isdigit(s[i + 1]) || s[i + 1] == '+' || s[i + 1] == '-'))) {
          return false;
        }
        if (i == 0 || (i == 1 && !isdigit(s[i - 1]))) {
          return false;
        }
        if (isE) {
          return false;
        }
        isE = true;
        continue;
      }
      if (!isdigit(s[i])) {
        return false;
      }
    }
    return true;
  }
};
// 官方的状态机做法
class Solution1 {
public:
  enum State {
    STATE_INITIAL,
    STATE_INT_SIGN,
    STATE_INTEGER,
    STATE_POINT,
    STATE_POINT_WITHOUT_INT,
    STATE_FRACTION,
    STATE_EXP,
    STATE_EXP_SIGN,
    STATE_EXP_NUMBER,
    STATE_END
  };

  enum CharType { CHAR_NUMBER, CHAR_EXP, CHAR_POINT, CHAR_SIGN, CHAR_ILLEGAL };

  CharType toCharType(char ch) {
    if (ch >= '0' && ch <= '9') {
      return CHAR_NUMBER;
    } else if (ch == 'e' || ch == 'E') {
      return CHAR_EXP;
    } else if (ch == '.') {
      return CHAR_POINT;
    } else if (ch == '+' || ch == '-') {
      return CHAR_SIGN;
    } else {
      return CHAR_ILLEGAL;
    }
  }

  bool isNumber(string s) {
    unordered_map<State, unordered_map<CharType, State>> transfer{
        {STATE_INITIAL,
         {{CHAR_NUMBER, STATE_INTEGER},
          {CHAR_POINT, STATE_POINT_WITHOUT_INT},
          {CHAR_SIGN, STATE_INT_SIGN}}},
        {STATE_INT_SIGN,
         {{CHAR_NUMBER, STATE_INTEGER}, {CHAR_POINT, STATE_POINT_WITHOUT_INT}}},
        {STATE_INTEGER,
         {{CHAR_NUMBER, STATE_INTEGER},
          {CHAR_EXP, STATE_EXP},
          {CHAR_POINT, STATE_POINT}}},
        {STATE_POINT, {{CHAR_NUMBER, STATE_FRACTION}, {CHAR_EXP, STATE_EXP}}},
        {STATE_POINT_WITHOUT_INT, {{CHAR_NUMBER, STATE_FRACTION}}},
        {STATE_FRACTION,
         {{CHAR_NUMBER, STATE_FRACTION}, {CHAR_EXP, STATE_EXP}}},
        {STATE_EXP,
         {{CHAR_NUMBER, STATE_EXP_NUMBER}, {CHAR_SIGN, STATE_EXP_SIGN}}},
        {STATE_EXP_SIGN, {{CHAR_NUMBER, STATE_EXP_NUMBER}}},
        {STATE_EXP_NUMBER, {{CHAR_NUMBER, STATE_EXP_NUMBER}}}};

    int len = s.length();
    State st = STATE_INITIAL;

    for (int i = 0; i < len; i++) {
      CharType typ = toCharType(s[i]);
      if (transfer[st].find(typ) == transfer[st].end()) {
        return false;
      } else {
        st = transfer[st][typ];
      }
    }
    return st == STATE_INTEGER || st == STATE_POINT || st == STATE_FRACTION ||
           st == STATE_EXP_NUMBER || st == STATE_END;
  }
};
