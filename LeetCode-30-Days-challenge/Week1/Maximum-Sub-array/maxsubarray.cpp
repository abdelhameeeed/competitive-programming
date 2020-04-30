class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size() ;
        if( n == 0 ) return 0 ;
        for( int i = 1 ; i < n ; i ++ )
        {
            nums[ i ] += nums[ i - 1 ] ;
        }
        int minn = 0 , ans  = INT_MIN ;
        for(int i = 0 ; i < n ; i ++ )
        {
            ans = max( ans , nums[i] - minn ) ;
            minn = min(minn , nums[i] ) ;
        }
        return ans ;
    }
};
