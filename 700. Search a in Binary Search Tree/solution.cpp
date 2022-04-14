#include <bits/stdc++.h>

class Solution {
public:
  TreeNode *searchBST(TreeNode *root, int val) {
    while (root) {
      if (val == root->val) {
        return root;
      }
      root = val < root->val ? root->left : root->right;
    }

    return nullptr;
  }
};
