class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* curr=root;

        while(curr!=NULL){
            if(curr->left==NULL){
                ans.push_back(curr->val);
                curr=curr->right;
            } else {
                TreeNode* ip=curr->left;
                while(ip->right!=NULL && ip->right!=curr){
                    ip=ip->right;
                }
                if(ip->right==NULL){
                    ip->right=curr;
                    curr=curr->left;
                }else {
                    ip->right=NULL;
                    ans.push_back(curr->val);
                    curr=curr->right;
                }
            }
        }
        return ans;
    }
};
