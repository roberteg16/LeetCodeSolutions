#include "../common.h"

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
  struct NodeRowAndCol {
    TreeNode *Node;
    int Row;
    int Col;
  };

public:
  vector<vector<int>> verticalTraversal(TreeNode *root) {
    unordered_map<int, vector<int>> colToValsMap;
    set<int> colsSet;

    queue<NodeRowAndCol> q;
    q.push({root, 0, 0});

    int prevRow = 0;
    map<int, vector<int>> valsOfCol;
    while (!q.empty()) {
      auto [node, row, col] = q.front();
      q.pop();

      if (prevRow != row) {
        for (auto &col : valsOfCol) {
          sort(col.second.begin(), col.second.end());
          auto &vals = colToValsMap[col.first];
          vals.insert(vals.end(), col.second.begin(), col.second.end());
        }
        valsOfCol.clear();
      }

      valsOfCol[col].push_back(node->val);
      colsSet.insert(col);

      if (node->left)
        q.push({node->left, row + 1, col - 1});
      if (node->right)
        q.push({node->right, row + 1, col + 1});

      prevRow = row;
    }

    for (auto &col : valsOfCol) {
      sort(col.second.begin(), col.second.end());
      auto &vals = colToValsMap[col.first];
      vals.insert(vals.end(), col.second.begin(), col.second.end());
    }

    vector<int> cols(colsSet.begin(), colsSet.end());
    sort(cols.begin(), cols.end());

    vector<vector<int>> result;
    for (auto idx : cols) {
      result.push_back(move(colToValsMap[idx]));
    }

    return result;
  }
};