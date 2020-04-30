class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int j = 0 , k = 0 ;
        for( int i = 0 ; i < S.size() ;  i ++ )
        {
            if( S[i]  != '#' ) {S[j] = S[i] ;j++;}
            else  j = max( j - 1 , 0 ) ;
        }
        for( int i = 0 ; i < T.size() ;  i ++ )
        {
            if( T[i]  != '#' ) {T[k] = T[i] ;k++;}
            else  k = max( k - 1 , 0 ) ;
        }
        if(j != k ) return false ;
        for( int i  = 0 ; i < j ; i ++ )
        {
            if(S[i] != T[i] ) return false ;
        }
        return true ;
    }
};
