class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int,bool>m;
        m[n]=  true ;
        int rev = reverse_rkm(n);
        m[rev] = true ;
          int cur = n ;
        while(true)
        {
            int gded = 0 ;
            while( cur > 0 )
            {
                int dig = cur % 10 ;
                cur /= 10 ;
                gded += (dig * dig ) ;
            }
            cur = gded ;
            if( gded == 1 ){
                return true ;
            }
            else if(m[gded] == true ) return false ;
            m[gded] = true ;
            int rev = reverse_rkm(gded) ;
            m[rev] = true ;
        }
    }
    int reverse_rkm(int gded)
    {
            int U = 1 ;
            vector<int>arkam ;
            while(gded < 0)
            {
                arkam.push_back(gded%10);
                gded/=10;
            }
            reverse(arkam.begin(),arkam.end());
            int any_rkm = 0 ;
            for( int i = 0 ; i < arkam.size() ; i ++ )
            {
                any_rkm += (U * arkam[i]) ;
                U *= 10 ;
            }
        return any_rkm;
    }
};
