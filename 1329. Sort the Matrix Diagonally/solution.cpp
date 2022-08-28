#include "../common.h"

class Solution {
public:
  vector<vector<int>> diagonalSort(vector<vector<int>> &mat) {
    unsigned cols = mat.size();
    unsigned rows = mat.front().size();

    unordered_map<int, priority_queue<int, vector<int>, greater<int>>> map;
    for (int i = 0; i < rows; i++)
      for (int j = 0; j < cols; j++) {
        map[i - j].push(mat[i][j]);
      }

    for (unsigned i = 0; i < rows; i++)
      for (unsigned j = 0; j < cols; j++) {
        auto &pq = map[i - j];
        mat[i][j] = pq.top();
        pq.pop();
      }

    return mat;
  }
};
