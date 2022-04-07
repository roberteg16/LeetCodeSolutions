#include <bits/stdc++.h>

static std::vector<int> SortIndexes(const std::vector<int> &v) {
  std::vector<int> idx(v.size());
  std::iota(idx.begin(), idx.end(), 0);

  std::stable_sort(idx.begin(), idx.end(),
                   [&v](size_t i1, size_t i2) { return v[i1] < v[i2]; });

  return idx;
}

class Solution {
public:
  std::vector<int> twoSum(std::vector<int> &nums, int target) {
    auto idxs = SortIndexes(nums);
    std::sort(nums.begin(), nums.end());

    int startIdx = 0;
    int finishIdx = nums.size() - 1;

    while (startIdx != finishIdx) {
      const int leftVal = nums[startIdx];
      const int rightVal = nums[finishIdx];

      const int sum = leftVal + rightVal;
      if (sum < target) {
        startIdx++;
      } else if (sum > target) {
        finishIdx--;
      } else {
        return {idxs[startIdx], idxs[finishIdx]};
      }
    }

    return {};
  }
};
