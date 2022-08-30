#include "../common.h"

class Solution {
public:
  string convert(string s, int numRows) {
    const int nDiagElements = std::max(0, numRows - 2);
    const unsigned sSize = s.size();

    string result;
    result.resize(sSize);

    unsigned idx = 0;
    for (int nRow = 0; nRow < numRows; nRow++) {
      unsigned stringIdx = nRow;

      while (stringIdx < sSize) {
        result[idx] = s[stringIdx];
        idx++;

        if (nRow != 0 && nRow != numRows - 1) {
          unsigned elemOnDiagIdx = (stringIdx + ((numRows - 1) - nRow) * 2);
          if (elemOnDiagIdx < sSize) {
            result[idx] = s[elemOnDiagIdx];
            idx++;
          }
        }

        stringIdx += (numRows + nDiagElements);
      }
    }

    return result;
  }
};
