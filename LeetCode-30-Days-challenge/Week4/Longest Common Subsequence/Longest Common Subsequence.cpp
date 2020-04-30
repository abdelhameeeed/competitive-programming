class Solution {
public:
    int n , m ;
    string s , t ;
    int longestCommonSubsequence(string text1, string text2)
    {
            n=text1.size();
            m=text2.size();
            s=text1,t=text2;
            return solve() ;
    }
    int solve()
    {
        /*
        if(i == n || j == m ) return 0 ;
        int &ret =  memo[i][j] ;
        if(~ret) return ret ;
        if(s[i] == t[j] ) ret = 1 + solve(i+1,j+1);
        else ret = max( solve(i+1,j),solve(i,j+1));
        return ret ;
        */
        int memo[n+1][m+1] ;
        memset(memo,0,sizeof(memo) ) ;
        for(int i = n - 1 ; i >= 0  ; i -- )
        {
            for(int j = m - 1 ; j >= 0 ; j -- )
            {
                  if(s[i]==t[j]){  memo[i][j] = 1 + memo[i+1][j+1];  }
                else
                {
                   memo[i][j] = max(memo[i][j+1] , memo[i+1][j]);
                }


            }
        }
        return memo[0][0];
    }
};
