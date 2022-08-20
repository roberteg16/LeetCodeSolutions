#include <algorithm>
#include <queue>
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
  vector<double> averageOfLevels(TreeNode *root) {
    if (!root) {
      return {};
    }

    std::vector<double> result;
    std::queue<TreeNode *> q;
    q.push(root);

    while (!q.empty()) {
      long n = q.size();
      long acc = 0;

      for (unsigned i = 0; i < n; i++) {
        TreeNode *node = q.front();
        q.pop();
        acc += node->val;
        if (node->left)
          q.push(node->left);
        if (node->right)
          q.push(node->right);
      }

      result.push_back(static_cast<double>(acc) / n);
    }

    return result;
  }
};