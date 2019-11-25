
/* https://codeforces.com/contest/478/problem/D*/
#include<iostream>
#include<bits/stdc++.h>
#include<bits/stdc++.h>
typedef long long ll  ;
using namespace std   ;
int  dx[] = {0, 0, 1, -1 } ;
int  dy[] = {1,-1,0, 0 }   ;
char dir[] = { 'R', 'L', 'D', 'U' } ;
int r, g ;
ll gg = 0  ;
ll levels = 0  ;
const int modd = 1e9 + 7  ;
const int sizee = 1e5 + 5 ;
ll dp[sizee] ;
ll memo[(int)2][(int) 2e5 + 5 ]  ;
/*
ll solve( int cur_lev, int cur_red )
{
    if( cur_lev > levels )
    {
        return 1 ;
    }
    ll res = 0   ;
    if( cur_red >= cur_lev )
    {
        res =  solve( cur_lev + 1, cur_red - cur_lev ) ;
    }
    int remain_r = r - cur_red ;
    int remain_g =  g  - ( dp[cur_lev-1] - remain_r )  ;
    if ( remain_g >= cur_lev )
    {
        res += solve( cur_lev + 1, cur_red ) ;
    }
    return res ;
}
*/
int main()
{
    cin >> r >> g ;
    gg = r + g    ;
    ll l = 1, rr = 1e3, mid = 0 ;
    while( l <=  rr )
    {
        mid = ( l + rr ) >> 1 ;
        if( ( mid *  ( mid + 1 ) ) / 2  > gg )
            rr = mid - 1 ;
        else
        {
            levels = max( levels, l ) ;
            l = l + 1 ;
        }
    }
    for( int i = levels  ; i >= 1 ; i --  )
    {
        dp[i] = i ;
        dp[i] = ((ll) dp[i] + dp[i+1] ) % modd  ;
    }
    for( int i = 0 ; i < 2e5 + 5 ; i ++ )
        memo[0][i] = 1 ;
    int countt = 1 ;
    int temp = 0   ;
    for( int i = 1 ; i <= levels ;  ++ i )
    {
        for(int k = 0 ; k <= r ; k ++ )
        {
            memo[countt][k] = 0 ;
        }
        for ( int j = 0 ; j <= r ; j ++ )
        {
            if ( j >= i )
            {
                memo[countt][j] =( memo[countt][j] + memo[temp][j-i] ) % modd ;
            }
            int remain_r = r - j ;
            int remain_g =  g  - ( dp[ i + 1 ] - remain_r )  ;
            if ( remain_g >= i )
            {
                memo[countt][j] = (memo[countt][j] + memo[ temp ][ j ] ) % modd ;
            }
        }
        swap( temp, countt ) ;
    }
    cout << memo[temp][r] << endl ;
    return 0  ;
}
