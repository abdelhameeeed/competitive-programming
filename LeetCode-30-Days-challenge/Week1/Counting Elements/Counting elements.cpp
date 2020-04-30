class Solution {
public:
    int freq[(int)1e3+5] ;
    int countElements(vector<int>& arr) {
        int maxx = 0 , ans = 0 ;
        for(int i = 0 ; i < arr.size() ; i++ )
        {
            maxx = max( maxx , arr[i] ) ;
            ++ freq[arr[i]] ;
        }
        for(int i = 0 ; i < maxx ; i ++ )
        {
            if( freq[i] && freq[i+1] ) ans += freq[i] ;
        }
        return ans ;
    }
};
