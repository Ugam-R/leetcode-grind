class Solution {
public:

    bool isSafe(vector<string> &boards,int row,int col,int n){
        for(int j=0;j<n;j++){
            if(boards[row][j]=='Q'){
                return false;
            }
        }

        for(int i=0;i<n;i++){
            if(boards[i][col]=='Q'){
                return false;
            }
        }

        for(int i=row,j=col;i>=0&&j>=0;i--,j--){
            if(boards[i][j]=='Q'){
                return false;
            }
        }

        for(int i=row,j=col;i>=0&&j<n;i--,j++){
            if(boards[i][j]=='Q'){
                return false;
            }
        }
        return true;
    }

    void nqueens(vector<string> &boards,int row,int n,vector<vector<string>> &ans){
        if(row==n){
            ans.push_back({boards});
            return;
        }
        for(int j=0;j<n;j++){
            if(isSafe(boards,row,j,n)){
                boards[row][j]='Q';
                nqueens(boards,row+1,n,ans);
                boards[row][j]='.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> boards(n,string(n,'.'));
        vector<vector<string>> ans;
        nqueens(boards,0,n,ans); 
        return ans;
    }
};
