class Solution {
public:
    unordered_map<int,int>dp ;
    int subarraySum(vector<int>& nums, int k) {

        for(int i = 1 ; i < nums.size() ; i ++ )
        {
             nums[i] = nums[i] + nums[i-1] ;
        }
        int ans = 0 ;
        dp[0] = 1   ;
        for( int i =  0 ; i < nums.size() ; i ++ ){
            ans += dp[  nums[i]  - k ] ;
            ++ dp[nums[i]] ;
        }
        return ans ;
    }

};
