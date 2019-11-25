/* https://codeforces.com/contest/580/problem/D */
#include<iostream>
#include<bits/stdc++.h>
typedef long long ll  ;
using namespace std   ;
int n, m, k ;
const int sizee2 = 22 ;
ll memo[(int)262150][sizee2];
int N[sizee2]    ;
map< pair < int, int >, int > mm ;
int check( int n )
{
    int o = 0 ;
    while( n )
    {
        if( n & 1 )
            ++o ;
        n = n >> 1 ;
    }
    return o ;
}
ll solve( int mask, int prev )
{
    if( check( mask ) == m )
        return 0 ;
    ll &ret = memo[mask][prev+1]   ;
    if(~ret)
        return ret          ;
    ret = 0 ;
    for( int i = 0 ; i < n ; i ++ )
    {
        if( ! ( mask & ( 1 << i ) ) )
        {
            ret = max( ret, mm[ { prev, i } ] +
                       solve( ( mask | ( 1 << i ) ), i ) + N[i] ) ;
        }
    }
    return ret ;
}
int main()
{
    memset( memo, -1, sizeof ( memo ) ) ;
    int xi, yi, ci     ;
    cin >> n >> m >> k ;
    for( int i = 0 ; i < n ; i ++ )
        cin >> N[i] ;
    for( int i = 1 ; i <= k ; i ++ )
    {
        cin >> xi >> yi >> ci      ;
        mm[ { xi - 1, yi - 1  } ] = ci     ;
    }
    cout << solve( 0, -1 )  << endl ;
    return 0 ;
}
