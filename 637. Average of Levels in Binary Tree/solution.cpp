#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

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
public:
  void visitAndAccumulate(
      TreeNode *tree, unsigned depth,
      std::unordered_map<unsigned, std::vector<double>> &levelAndMaxVal) {
    if (!tree) {
      return;
    }
    levelAndMaxVal[depth].push_back(tree->val);
    visitAndAccumulate(tree->left, depth + 1, levelAndMaxVal);
    visitAndAccumulate(tree->right, depth + 1, levelAndMaxVal);
  }

  vector<double> averageOfLevels(TreeNode *root) {
    std::unordered_map<unsigned, std::vector<double>> levelAndMaxVal;
    visitAndAccumulate(root, 0u, levelAndMaxVal);

    std::vector<double> result;
    result.reserve(levelAndMaxVal.size());
    for (unsigned i = 0; i < levelAndMaxVal.size(); i++) {
      double avg = 0;
      for (double val : levelAndMaxVal[i]) {
        avg += val;
      }
      result.push_back(avg / levelAndMaxVal[i].size());
    }

    return result;
  }
};