class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0 ;
        for(int i = 0 ; i < prices.size() ; ){
            int temp = i  ;
            int j = i + 1 ;
            while( j < prices.size()   && temp < prices.size() )
            {
                if( prices[j] > prices[temp] )
                {
                  temp = j ;
                  ++ j     ;
                }
                else break ;
            }
            ans += ( prices[temp] - prices[i] ) ;
            i = j ;
        }
        return ans ;
    }
};
