class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size() ;
        vector<pair<string,string>>v  ;
        vector<vector<string>>ans ;
        for(int i = 0 ; i < n ; i ++ )
        {
            string t = strs[i] ;
            sort(t.begin(),t.end());
            v.push_back({t,strs[i]});
        }
        sort(v.begin(),v.end());
        vector<string>G;
        G.push_back(v[0].second);
        string temp = v[0].first ;
        for( int i = 1 ; i < v.size() ; i ++ )
        {
            if(v[i].first == temp ){
                G.push_back(v[i].second);
            }
            else{
                temp = v[i].first ;
                ans.push_back(G) ;
                G.clear();
                G.push_back(v[i].second);
            }
        }
        if(G.size()){ans.push_back(G);}
        return ans ;
    }
};
