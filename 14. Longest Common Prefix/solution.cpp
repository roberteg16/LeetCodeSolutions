#include "../common.h"

class Solution {
public:
  string longestCommonPrefix(vector<string> &strs) {
    // Retrieve the smallest string, this is the maximum longestCommonPrefix
    auto it = min_element(strs.begin(), strs.end(),
                          [](const std::string &lhs, const std::string &rhs) {
                            return lhs.size() < rhs.size();
                          });
    if (it == strs.end()) {
      return "";
    }

    const unsigned maxCommonPrefix = it->size();

    // Longest common prefix lies between 0 and the smallest string
    unsigned currentIdx = 0;
    for (; currentIdx < maxCommonPrefix; currentIdx++) {
      for (unsigned i = 0; i < strs.size() - 1; i++) {
        if (strs[i][currentIdx] != strs[i + 1][currentIdx]) {
          return strs.front().substr(0, currentIdx);
        }
      }
    }

    return strs.front().substr(0, currentIdx);
  }
};