class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int N = nums.size() ;
        vector<int>ans   ;
        ans.resize(N)    ;
        int R_sofar = 1  ;
        ans[0] = nums[0] ;
        for( int i = 1 ; i < ans.size() ; i ++ ) ans[i] = nums[i] * ans[i-1] ;
        for( int i = N-1 ; i >= 0 ; i -- )
        {
            if( i + 1 == N ) ans[i] = ans[i-1]  ;
            else if( i-1 < 0 ) ans[i] = R_sofar ;
            else ans[i] = ans[i-1] *  R_sofar   ;
            R_sofar *= nums[i] ;
        }
        return ans ;
    }
};


