class Solution {
public:

    int prevorder=0;

    int kthSmallest(TreeNode* root, int k) {
        if(root==NULL){
            return -1;
        }
        if(root->left!=NULL){
            int leftans=kthSmallest(root->left,k);
            if(leftans!=-1){
                return leftans;
            }
        }
        if(prevorder+1 == k){
            return root->val;
        }
        prevorder+=1;
        if(root->right!=NULL){
            int rightans=kthSmallest(root->right,k);
            if(rightans!=-1){
                return rightans;
            }
        }
        return -1;
    }
};
