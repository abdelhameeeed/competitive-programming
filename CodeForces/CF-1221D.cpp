/*https://codeforces.com/contest/1221/problem/D*/
#include<bits/stdc++.h>
typedef long long ll  ;
using namespace std   ;
int  dx[] = {0, 0, 1, -1 } ;
int  dy[] = {1,-1,0, 0 }   ;
char dir[] = { 'R', 'L', 'D', 'U' } ;
template< class InputIt, class Distance >
void advance( InputIt& it, Distance n );
const int sizee = 3e5 + 5  ;
ll N[sizee] ;
ll cost[sizee] ;
int n ;
ll dp[(int)3e5+5][(int)3] ;
ll solve( int pos, int prev_add )
{
    if(pos == n )
        return 0  ;
    ll &ret = dp[pos][prev_add] ;
    if( ~ret )
        return ret ;
    ret = 1e18 ;
    for( int i = 0 ; i <= 2 ; i ++ )
    {
        if( pos - 1 >= 0 )
        {
            if( N[pos] + i != N[ pos - 1 ] + prev_add )
            {
                ret = min( ret, (ll) i * cost[pos] + solve( pos + 1, i )   ) ;
            }
        }
        if( pos == 0  )
        {
            ret = min( ret, (ll) i * cost[pos] + solve( pos + 1, i )   ) ;
        }
    }
    return ret ;
}
int main()
{
    ios::sync_with_stdio() ;
    cin.tie(0)  ;
    cout.tie(0) ;
    int q ;
    cin >> q ;
    while(q--)
    {
        cin >>  n ;
        for(int i = 0 ; i <= n ; i ++ )
        {
            dp[i][0] = - 1 ;
            dp[i][1] = - 1 ;
            dp[i][2] = - 1 ;
        }
        for(int i = 0 ; i < n ; i ++ )
        {
            cin >> N[i] >> cost[i] ;
        }
        cout << solve( 0, 0 ) << '\n' ;
    }
    return 0    ;
}
