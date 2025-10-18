class Solution {
public:
    void nextPermutation(vector<int>& A) {
        int pvit=-1,n=A.size();
        for(int i=n-2;i>=0;i--){
            if(A[i]<A[i+1]){
                pvit=i;
                break;
            }
        }
        if(pvit==-1){
            reverse(A.begin(),A.end());
            return;
        }
        for(int i=n-1;i>pvit;i--){
            if(A[i]>A[pvit]){
                swap(A[i],A[pvit]);
                break;
            }  
        }
        int i=pvit+1,j=n-1;
        while(i<=j){
            swap(A[i++],A[j--]);
        }
    }
};
