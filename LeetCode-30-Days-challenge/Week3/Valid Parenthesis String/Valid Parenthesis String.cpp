class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size()  ;
        if( !n ) return 1;
        stack < int > ss ;
        stack< int> mark ;
        for(int i = 0 ; i < n ; i ++ )
        {
             if( s[i] == '*' ) mark.push(i)  ;
             else if(s[i]=='(') ss.push( i ) ;
            else
            {
               if( ss.size() ) ss.pop() ;
                else if( !ss.size() )
                {
                    if(mark.size()){
                        s[ mark.top() ] ='-';
                        mark.pop() ;
                    }
                    else return false ;
                }
            }
        }
        if( ss.size() )
        {
            while( ss.size() )
            {
                int cur = ss.top() ;
                ss.pop() ;
                bool f = false ;
                for(int i = cur + 1 ; i < n ; i ++ ){
                    if( s[i] =='*' ) { s[i] = '-' ; f = true ; break ; }
                }
                if( !f ) return false ;
            }
        }
        return true ;
    }
};
