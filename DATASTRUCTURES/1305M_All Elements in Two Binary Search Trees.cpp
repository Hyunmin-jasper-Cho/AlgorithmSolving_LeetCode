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
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        TreeNode *pt1, *pt2;
        vector<int> ans;
        vector<int> o1, o2;
        
        inorder(root1, o1);
        inorder(root2, o2);
        
        int itr1 = 0, itr2 = 0;
        while (itr1 < (int) o1.size() && itr2 < (int) o2.size()) {
            if (o1[itr1] <= o2[itr2]) ans.push_back(o1[itr1++]);
            else ans.push_back(o2[itr2++]);
        }
        
        while (itr1 != (int) o1.size()) ans.push_back(o1[itr1++]);
        while (itr2 != (int) o2.size()) ans.push_back(o2[itr2++]);
        
        return ans;
    }
    
private:
    void inorder(TreeNode* root, vector<int>& v) {
        if (root == nullptr) return;
        
        
        // inorder process
        if (root->left != nullptr) inorder(root->left, v);
        v.push_back(root->val);
        if (root->right != nullptr) inorder(root->right, v);
    }    
};
