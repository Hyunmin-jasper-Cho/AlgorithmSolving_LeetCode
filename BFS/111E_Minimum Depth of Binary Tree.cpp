class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        
        
        
        queue<TreeNode *> q;
        q.push(root);
        
        int min_depth = 1;
        while (true) {
            
            int size = (int) q.size();
            
            for (int i = 0; i < size; ++i) {
                
                TreeNode *tn = q.front(); q.pop();
                
                bool el = false; 
                bool er = false;
                
                if (tn->left != nullptr) {
                    q.push(tn->left);
                    el = true;
                }
                if (tn->right != nullptr) {
                    q.push(tn->right);
                    er = true;
                }
                
                if (el == false and er == false) return min_depth;
            } min_depth++;
        }
    }
};
