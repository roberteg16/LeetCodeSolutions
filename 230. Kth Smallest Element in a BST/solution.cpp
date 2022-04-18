#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int kthSmallestImpl(TreeNode* root, int &k) {
        int result = root->left ? kthSmallestImpl(root->left, k) : -1;
        if (result != -1) {
            return result;
        } 
        
        if (k == 1) {
            return root->val;
        }
        
        // We already check one that was smaller, decrease
        k--;
        return root->right ? kthSmallestImpl(root->right, k) : -1;
    }
    
    int kthSmallest(TreeNode* root, int k) {
        return kthSmallestImpl(root, k);
    }
};