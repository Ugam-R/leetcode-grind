class Solution {
public:

    TreeNode* lastvisit=NULL;

    void flatten(TreeNode* root) {
        if(root==NULL){
            return;
        }
        flatten(root->right);
        flatten(root->left);
        root->left=NULL;
        root->right=lastvisit;
        lastvisit=root;
    }
};
