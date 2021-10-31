class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        unordered_map<int, int> m;
        
        int ans = 0;
        int depth = 0;
        
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            
            int size = (int) q.size();
            for (int i = 0; i < size; ++i) {
                TreeNode *n = q.front(); q.pop();
                
                if (n->left == nullptr and n->right == nullptr) {
                    if (m.find(depth) == m.end()) {
                        m.insert({depth, n->val});
                    } else m[depth] = m[depth] + n->val;
                }
                
                if (n->left != nullptr) q.push(n->left);
                if (n->right != nullptr) q.push(n->right);
            } depth++;
        }
        
        return m[depth - 1];
    } 
};
