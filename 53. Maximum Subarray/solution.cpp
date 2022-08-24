#include <vector>
#include <limits>

using namespace std;

// KADANE'S ALGORITHM
class Solution {
public:
  int maxSubArray(vector<int> &nums) { 
    int globalMaxVal = std::numeric_limits<int>::min();
    int localMaxVal = 0;

    for (const int num : nums) {
      localMaxVal += num;

      if (localMaxVal > globalMaxVal) {
        globalMaxVal = localMaxVal;
      }

      if (localMaxVal < 0) {
        localMaxVal = 0;
      }
    }
    
    return globalMaxVal;
  }
};
