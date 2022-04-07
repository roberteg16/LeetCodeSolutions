#include <bits/stdc++.h>

class Solution {
public:
  int lastStoneWeight(std::vector<int> &stones) {
    unsigned currentSize = stones.size();
    while (currentSize > 1) {
      std::sort(stones.begin(), stones.begin() + currentSize);

      const int &heaviestStone = stones[currentSize - 1];
      int &secondHeaviestStone = stones[currentSize - 2];

      if (heaviestStone != secondHeaviestStone) {
        secondHeaviestStone = heaviestStone - secondHeaviestStone;
        currentSize--;
      } else {
        currentSize -= 2;
      }
    }

    return currentSize ? stones.front() : 0;
  }
};
