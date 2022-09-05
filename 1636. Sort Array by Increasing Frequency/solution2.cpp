#include "../common.h"
#include <unordered_map>

class Solution {
public:
  vector<int> frequencySort(vector<int> &nums) {
    unordered_map<int, int> valAndFreq;
    for (auto n : nums)
      valAndFreq[n]++;

    sort(nums.begin(), nums.end(), [&](const int lhs, const int rhs) {
      return valAndFreq[lhs] == valAndFreq[rhs]
          ? lhs > rhs : valAndFreq[lhs] < valAndFreq[rhs];
    });

    return nums;
  }
};
