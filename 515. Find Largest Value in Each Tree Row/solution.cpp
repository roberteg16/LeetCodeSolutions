/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
  void visitAndAnnotate(TreeNode *tree, unsigned depth,
                        std::unordered_map<unsigned, int> &levelAndMaxVal) {
    if (!tree) {
      return;
    }

    auto it = levelAndMaxVal.find(depth);
    if (it == levelAndMaxVal.end()) {
      levelAndMaxVal[depth] = tree->val;
    } else {
      it->second = std::max(tree->val, it->second);
    }

    visitAndAnnotate(tree->left, depth + 1, levelAndMaxVal);
    visitAndAnnotate(tree->right, depth + 1, levelAndMaxVal);
  }

  std::vector<int> largestValues(TreeNode *root) {
    std::unordered_map<unsigned, int> levelAndMaxVal;
    visitAndAnnotate(root, 0u, levelAndMaxVal);

    std::vector<int> result;
    result.reserve(levelAndMaxVal.size());
    for (unsigned i = 0; i < levelAndMaxVal.size(); i++) {
      result.push_back(levelAndMaxVal[i]);
    }
    return result;
  }
};