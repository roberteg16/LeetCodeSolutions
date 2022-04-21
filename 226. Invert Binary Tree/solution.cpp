#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) {
            return nullptr;
        }
        
        auto left = root->left;
        auto right = root->right;
        root->left = right;
        root->right = left;
        
        invertTree(root->left);
        invertTree(root->right);
            
        return root;
    }
};