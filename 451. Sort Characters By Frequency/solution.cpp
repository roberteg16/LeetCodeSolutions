#include "../common.h"

class Solution {
public:
  string frequencySort(string s) {
    unordered_map<char, unsigned> charFreqMap;
    for (auto c : s)
      charFreqMap[c]++;
    sort(s.begin(), s.end(), [&](char lhs, char rhs) {
      return charFreqMap[lhs] == charFreqMap[rhs]
                 ? lhs < rhs
                 : charFreqMap[lhs] > charFreqMap[rhs];
    });

    return s;
  }
};
