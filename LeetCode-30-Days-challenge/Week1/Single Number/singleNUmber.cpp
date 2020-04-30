class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int>freq;
        for ( int i = 0 ; i < nums.size() ; i ++ ){++freq[nums[i]]; }
	    unordered_map<int, int>::iterator it = freq.begin();
        int c = 0 , w = 0 ;
        while (it != freq.end())
	{
		c = it->first;
		w = it->second;

        if( w == 1 )
            break ;
		it++;
	}
        return c ;
    }
};
