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
    TreeNode *ans = nullptr;
    TreeNode* findNearestRightNode(TreeNode* root, TreeNode* u) {
        inorder(root, u->val, 0);
        return ans;
    }
private:
    #define undefined -2
    
    
    int target_level = undefined;
    
    void inorder(TreeNode *root, int target_value, int current_level) {
        if (root == nullptr) return;
        
        inorder(root->left, target_value, current_level + 1);
        
        if (target_level == undefined) {
            if (root->val == target_value) target_level = current_level;
        } else {
            if (current_level == target_level) {
                if (ans == nullptr) ans = root;
                return;
            }
        }
        
        inorder(root->right, target_value, current_level + 1);
        
        
    }
};
