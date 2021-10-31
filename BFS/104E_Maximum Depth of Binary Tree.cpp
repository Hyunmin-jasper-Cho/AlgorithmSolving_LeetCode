class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        
        queue<TreeNode *> q;
        
        int depth = 0;
        q.push(root);
        while (!q.empty()) {
            int size = (int) q.size();
            for (int i = 0; i < size; ++i) {
                TreeNode *tn = q.front(); q.pop();
                if (tn->left != nullptr) q.push(tn->left);
                if (tn->right != nullptr) q.push(tn->right);
            } depth++;
        } return depth;
    }
};
