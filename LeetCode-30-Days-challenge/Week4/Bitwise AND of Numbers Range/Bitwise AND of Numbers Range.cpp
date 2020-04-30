class Solution {
public:
    long long  rangeBitwiseAnd(long long  m, long long  n) {
        long long  res = 0 ;
        while(m&&n){
        int msb_p1 = msbPos(m);
        int msb_p2 = msbPos(n);

        if (msb_p1 != msb_p2)
            break;
        long long  msb_val =  (1 << msb_p1);
        res = res + msb_val ;

        m = m - msb_val;
        n = n - msb_val;
        }
       return res ;
    }

    int msbPos(long long  n)
{
    int msb_p = -1;
    while (n)
    {
        n = n>>1;
        msb_p++;
    }
    return msb_p;
}
};
