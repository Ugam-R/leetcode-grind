class Solution {
public:
    TreeNode* prev=NULL;

    int minDiffInBST(TreeNode* root) {
        if(root==NULL){
            return INT_MAX;
        }
        int ans=INT_MAX;
        if(root->left!=NULL){
            int leftmin=minDiffInBST(root->left);
            ans=min(ans,leftmin);
        }
        if(prev!=NULL){
            ans=min(ans,root->val-prev->val);
        }
        prev=root;
        if(root->right!=NULL){
            int rightmin=minDiffInBST(root->right);
            ans=min(ans,rightmin);
        }
        return ans;

    }
};
