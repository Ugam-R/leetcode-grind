class Solution {
public:

    void calsubset(vector<int>& nums,vector<int>& ans,int i,vector<vector<int>> &allsubset){
        if(i==nums.size()){
            allsubset.push_back(ans);
            return;
        }
    
        ans.push_back(nums[i]);
        calsubset(nums,ans,i+1,allsubset);

        ans.pop_back();
        int idx=i+1;
        while(idx<nums.size() && nums[idx]==nums[idx-1]){
            idx++;
        }
        calsubset(nums,ans,idx,allsubset);

    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> ans;
        vector<vector<int>> allsubset;
        calsubset(nums,ans,0,allsubset);
        return allsubset;
    }
};
