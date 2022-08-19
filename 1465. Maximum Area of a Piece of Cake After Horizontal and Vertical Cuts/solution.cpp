#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  int getMaxSpanOnCuts(vector<int> &cuts, int end) {
    int current = std::max(cuts[0], end - cuts.back());
    for (int i = 0; i < cuts.size() - 1; i++) {
      current = std::max(current, cuts[i+1] - cuts[i]);
    }
    return current;
  }

  int maxArea(int h, int w, vector<int> &horizontalCuts,
              vector<int> &verticalCuts) {
    std::sort(horizontalCuts.begin(), horizontalCuts.end());
    std::sort(verticalCuts.begin(), verticalCuts.end());
    int hMax = getMaxSpanOnCuts(horizontalCuts, h);
    int vMax = getMaxSpanOnCuts(verticalCuts, w);

    return (static_cast<long>(hMax) * static_cast<long>(vMax)) % 1000000007;
  }
};