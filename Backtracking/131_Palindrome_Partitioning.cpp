class Solution {
public:

    bool ispalindrome(string partition){
        string s2=partition;
        reverse(s2.begin(),s2.end());
        
        return s2==partition;
    }

    void helper(string s,vector<string> &part,vector<vector<string>> &ans){
        if(s.size()==0){
            ans.push_back(part);
            return;
        }
        for(int i=0;i<s.size();i++){
            string partition=s.substr(0,i+1);
            if(ispalindrome(partition)){
                part.push_back(partition);
                helper(s.substr(i+1),part,ans);
                part.pop_back();
            }
        }

    }

    vector<vector<string>> partition(string s) {
        vector<string> part;
        vector<vector<string>> ans;
        helper(s,part,ans);
        return ans;
    }
};
