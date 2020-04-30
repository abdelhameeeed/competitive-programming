class Solution {
public:
    int ans = 0 ;
    unordered_map< int , int > dp ;
    int findMaxLength(vector<int>& nums)
    {
        if( nums.size() == 0 ) return 0   ;
        if( nums[0] == 0 ) nums[ 0 ] = -1 ;
        for( int i = 1 ; i < nums.size() ; i ++ )
        {
            if(nums[i] == 0 ) nums[i] = -1 ;
            nums[i] += nums[i-1] ;
        }
        int ans = 0 ;
        dp[ nums[ 0 ] ]  = 1 ;
        for( int i = 1 ; i < nums.size() ; i ++ )
        {
            if( nums[i] == 0 ) ans = max( ans , i + 1 ) ;
            else
            {
            if(  dp[nums[i]]  != 0  ) ans = max( ans , ( i + 1 ) - dp[ nums[ i ]  ] ) ;
            else  dp[ nums[ i ] ]  = i + 1 ;
            }
        }
    return ans ;
    }
};
