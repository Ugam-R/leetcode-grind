class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL || q==NULL){
            return p==q;
        }
        bool isleftsame=isSameTree(p->left,q->left);
        bool isrightsame=isSameTree(p->right,q->right);
        return  isleftsame  && isrightsame && q->val==p->val; 
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==NULL || subRoot==NULL){
            return root==subRoot;
        }
        if(root->val==subRoot->val && isSameTree(root,subRoot)){
            return true;
        }
        return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
    }
};
