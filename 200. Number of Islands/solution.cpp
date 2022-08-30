#include "../common.h"

class Solution {
public:
  bool traverseLand(int i, int j, vector<vector<char>> &grid,
                    unordered_set<unsigned> &landOfIslands) {
    const int rows = grid.size();
    const int cols = grid[0].size();

    const unsigned uniqueIdx = i * cols + j;
    if (grid[i][j] == '0' || landOfIslands.count(uniqueIdx)) {
      return false;
    }

    landOfIslands.insert(uniqueIdx);

    if (i - 1 >= 0) traverseLand(i - 1, j, grid, landOfIslands);
    if (i + 1 < rows) traverseLand(i + 1, j, grid, landOfIslands);
    if (j - 1 >= 0) traverseLand(i, j - 1, grid, landOfIslands);
    if (j + 1 < cols) traverseLand(i, j + 1, grid, landOfIslands);

    return true;
  }

  int numIslands(vector<vector<char>> &grid) {
    unordered_set<unsigned> landOfIslands;
    int numIslands = 0;

    for (unsigned i = 0; i < grid.size(); i++) {
      for (unsigned j = 0; j < grid[0].size(); j++) {
        numIslands += traverseLand(i, j, grid, landOfIslands);
      }
    }
    return numIslands;
  }
};
