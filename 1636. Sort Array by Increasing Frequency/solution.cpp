#include "../common.h"

class Solution {
public:
  struct ValAndFreq {
    int Val;
    unsigned Freq;
  };

  vector<int> frequencySort(vector<int> &nums) {
    unsigned freq[202] = {0};
    for (auto n : nums)
      freq[n + 100]++;

    vector<ValAndFreq> valAndFreqs;
    for (int i = 0; i < 202; i++)
      valAndFreqs.push_back({i, freq[i]});

    sort(valAndFreqs.begin(), valAndFreqs.end(),
         [](const ValAndFreq lhs, const ValAndFreq rhs) {
           if (lhs.Freq == rhs.Freq)
             return lhs.Val < rhs.Val;
           return lhs.Freq < rhs.Freq;
         });

    vector<int> result;
    for (auto valAndFreq : valAndFreqs) {
      result.insert(result.begin(), valAndFreq.Freq, valAndFreq.Val);
    }

    return result;
  }
};
