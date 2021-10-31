class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr and q == nullptr) return true;
        else if (p == nullptr or q == nullptr) return false;
        else if (p->val != q->val) return false;
        
        queue<pair<TreeNode *, TreeNode *>> pq;
        pq.push({p, q});
        while (!pq.empty()) {
            
            int size = (int) pq.size();
            for (int i = 0; i < size; ++i) {
                TreeNode *ptmp = pq.front().first;
                TreeNode *qtmp = pq.front().second;
                pq.pop();
                
                if (ptmp->left == nullptr and qtmp->left == nullptr) {}
                else if (ptmp->left == nullptr or qtmp->left == nullptr) return false;
                else if (ptmp->left->val != qtmp->left->val) return false;
                else pq.push({ptmp->left, qtmp->left});
                
                
                if (ptmp->right == nullptr and qtmp->right == nullptr) {}
                else if (ptmp->right == nullptr or qtmp->right == nullptr) return false;
                else if (ptmp->right->val != qtmp->right->val) return false;
                else pq.push({ptmp->right, qtmp->right});
                
            }
        }
        
        return true;
    }
};
