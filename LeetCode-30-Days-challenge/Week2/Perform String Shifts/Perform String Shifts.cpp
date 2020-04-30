class Solution {
public:
    string stringShift( string s , vector< vector< int > > & shift ) {
        deque< char >q ;
        for( int i = 0 ; i < s.size() ; i ++ ){
            q.push_back( s[ i ] )  ;
        }
        int N = s.size() ;
        for( int i = 0 ; i < shift.size() ; i ++ )
        {
           int &ref2 = shift[i][1] ;
           int &ref1 = shift[i][0] ;
           if( ref2 >= N ) ref2 %= N ;
           if( ref1 == 0 )
           {
               while( ref2 != 0)
               {
                   q.push_back(  q.front() ) ;
                   q.pop_front() ;
                   --ref2 ;
               }
           }
            else
            {
                while(ref2!=0)
                {
                    q.push_front(  q.back() ) ;
                    q.pop_back() ;
                    --ref2 ;
                }
            }
        }
        s = "" ;
        while(q.size()){
            s+=q.front() ;
            q.pop_front() ;
        }
        return s ;
    }
};
