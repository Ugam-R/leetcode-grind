class Solution {
public:
    set<vector<int>> s;
    void helper(vector<int>& arr,int i, int tar,vector<vector<int>> &ans,vector<int> &combin){
        if(i==arr.size() || tar<0){
            return;
        }
        if(tar==0){
            if(s.find(combin)==s.end()){
                ans.push_back(combin);
                s.insert(combin);
            }
            return;
        }
        combin.push_back(arr[i]);
        helper(arr,i+1,tar-arr[i],ans,combin);
        helper(arr,i,tar-arr[i],ans,combin);
        combin.pop_back();
        helper(arr,i+1,tar,ans,combin);
    }

    vector<vector<int>> combinationSum(vector<int>& arr, int tar) {
        vector<vector<int>> ans;
        vector<int> combin;
        helper(arr,0,tar,ans,combin);
        return ans;
    }
};
