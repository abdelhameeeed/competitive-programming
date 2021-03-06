/* https://codeforces.com/contest/948/problem/C */
#include<bits/stdc++.h>
typedef long long ll  ;
using namespace std   ;
const long long INF64 = (long long)(1e18) + 100 ;
const int sizee = 1e5 + 5 ;
ll snow[sizee] ;
ll temp[sizee] ;
ll accum_temp[sizee] ;
int n  ;
map< ll, ll > m ;
ll freq[sizee]  ;
ll dp[sizee]    ;
ll ans[sizee] ;
int main()
{
    ios::sync_with_stdio() ;
    cin.tie(0)  ;
    cout.tie(0) ;
    cin >> n ;
    for(int i = 1 ; i <= n ; i ++ )
        cin >> snow[i] ;
    for( int i = 1 ; i <= n ;  i ++ )
        cin >> temp[i] ;
    for( int i = 0 ; i <= n ; i ++ )
    {
        accum_temp[i] = temp[i] ;
        accum_temp[i] = accum_temp[ i ] + accum_temp[ i - 1 ] ;
    }
    ll sub_accum = 0 ;
    int pos_ = 0 ;
    for( int i = 1 ; i <= n ; i ++ )
    {
        ll L = i, R = n, mid = 0 ;
        pos_ = n  ;
        while( L <= R )
        {
            mid = ( L + R ) / 2 ;
            if( accum_temp[mid] - sub_accum >= snow[i] )
            {
                pos_ = mid ;
                R = mid - 1 ;
            }
            else
                L = mid + 1 ;
        }
        dp[i] = pos_ ;
        sub_accum = sub_accum + temp[i] ;
    }
    sub_accum = 0 ;
    for( int i = 1 ; i <= n ; i ++ )
    {
        if( accum_temp[ dp [ i ] ] - sub_accum <= snow[i] )
        {
            ++ freq[i] ;
            -- freq[ dp[i]  + 1 ] ;
        }
        else
        {
            ++ freq[i] ;
            ll prev = accum_temp[ dp[i] - 1 ] - sub_accum ;
            -- freq[ dp[i] ] ;
            m[ dp [ i ] ] += snow[i] - ( accum_temp[ dp[i] - 1 ] - sub_accum ) ;
        }
        sub_accum = (ll) sub_accum + temp[i] ;
    }
    for( int i = 1 ; i <= n ; i ++ )
    {
        freq[i] += freq[i-1] ;
    }
    for( int i = 1 ; i <= n ; i ++ )
    {
        ans[i] = (ll) freq[i] * temp[i] + m[i] ;
    }
    for(int i = 1 ; i <= n ; i ++ )
    {
        cout << ans[i] <<" " ;
    }
    cout << '\n' ;
    return 0    ;
}
