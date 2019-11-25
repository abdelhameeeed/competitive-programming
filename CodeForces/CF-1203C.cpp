/* https://codeforces.com/contest/1203/problem/C */
#include<iostream>
#include<bits/stdc++.h>
#include<bits/stdc++.h>
typedef long long ll  ;
using namespace std   ;
/*
 * _._ _..._ .-',     _.._(`))
 *'-. `     '  /-._.-'    ',/
 *   )         \            '.
 *  / _    _    |             \
 * |  a    a    /              |
 * \   .-.     /               ;
 *  '-('' ).-'       ,'       ;
 *     '-;           |      .'
 *        \           \    /
 *        | 7  .__  _.-\   \
 *        | |  |  ``/  /`  /
 *       /,_|  |   /,_/   /
 *          /,_/      '`-'
 */
 int q  , n ;
 const int sizee = 4e5 + 5 ;
 ll N[sizee] ;
 ll gcd(ll a  , ll b )
 {
     if( b == 0 ) return a ;
     return gcd( b , a % b ) ;
 }
int main()
{
    cin >> n ;
    for( int i = 1 ; i <= n ; i ++ )
    {
        cin >> N[i] ;
    }
    ll Cur_g = N[1] ;
    for( int i = 2 ; i <= n ; i ++ )
    {
        Cur_g = gcd(  Cur_g , N[i] ) ;
    }
    ll ans = 0 ;
    for( int i = 1 ; i <= Cur_g / i ; i ++ )
    {
        if(Cur_g % i == 0 )
        {
            if( (ll) i * i != Cur_g ) ans += 2 ;
            else ans += 1 ;
        }
    }
    cout << ans << endl ;
    return 0 ;
}
