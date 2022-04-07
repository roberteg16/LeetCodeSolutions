
#include <bits/stdc++.h>

class Solution {
  unsigned GetValueOfLetter(char letter) {
    switch (letter) {
    case 'I':
      return 1;
    case 'V':
      return 5;
    case 'X':
      return 10;
    case 'L':
      return 50;
    case 'C':
      return 100;
    case 'D':
      return 500;
    case 'M':
      return 1000;
    }
  }

public:
  int romanToInt(std::string s) {
    if (s.empty()) {
      return 0;
    }

    if (s.size() == 1) {
      return GetValueOfLetter(s.front());
    }

    int result = 0;

    unsigned temporalAcc = GetValueOfLetter(s.front());

    for (unsigned i = 1; i < s.size(); i++) {
      const char lastLetter = s[i - 1];
      const char currentLetter = s[i];
      const unsigned lastLetterVal = GetValueOfLetter(lastLetter);
      const unsigned currentLetterVal = GetValueOfLetter(currentLetter);

      if (lastLetterVal == currentLetterVal) {
        temporalAcc += currentLetterVal;
      } else if (lastLetterVal > currentLetterVal) {
        result += temporalAcc;
        temporalAcc = currentLetterVal;
      } else if (lastLetterVal < currentLetterVal) {
        result -= temporalAcc;
        temporalAcc = currentLetterVal;
      }
    }

    return result + temporalAcc;
  }
};