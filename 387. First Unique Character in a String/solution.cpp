#include "../common.h"

class Solution {
public:
  int firstUniqChar(string s) {
    int lettersPos[26] = {-1};
    bool seen[26] = {false};

    for (unsigned i = 0; i < 26; i++) {
      lettersPos[i] = -1;
      seen[i] = false;
    }

    for (unsigned i = 0; i < s.size(); i++) {
      const char c = s[i] - 'a';
      lettersPos[c] = seen[c] ? -1 : (int)i;
      seen[c] = true;
    }

    int min = numeric_limits<int>::max();
    for (int pos : lettersPos) {
      if (pos == -1)
        continue;
      if (pos < min)
        min = pos;
    }

    return min == numeric_limits<int>::max() ? -1 : min;
  }
};
