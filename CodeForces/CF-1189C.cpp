
/*  https://codeforces.com/contest/1189/problem/C */
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
const int sizee = 1e5 + 5 ;
int N[sizee] ;
map< pair < int, int >, pair < int, int > > memo2  ;
pair<int,int> solve( int L, int R )
{
    if( L == R )
    {
        memo2[ {L,R}] = make_pair(N[L], 0 ) ;
        return make_pair( N[L], 0 ) ;
    }
    if ( memo2.count(make_pair(L,R)) )
    {
        return memo2[make_pair(L,R)] ;
    }
    int all = (( R - L ) + 1) >> 1  ;
    int to_right = ( L + all ) - 1  ;
    pair<int,int>p1 = solve( L, to_right )     ;
    pair<int,int>p2 = solve( to_right  + 1, R )   ;
    if( p1.first + p2.first >= 10 )
    {
        memo2[make_pair(L,R)]=make_pair(( p1.first + p2.first ) % 10, p2.second + p1.second + 1) ;
        return make_pair( ( p1.first + p2.first ) % 10, p2.second + p1.second + 1  ) ;
    }
    else
    {
        memo2[make_pair(L,R)]=make_pair(( p1.first + p2.first ) % 10, p2.second + p1.second ) ;
        return make_pair( ( p1.first + p2.first ) , p2.second + p1.second   ) ;
    }
}
int main()
{
    int n    ;
    cin >> n ;
    for( int i = 1 ; i <= n ; i ++ )
    {
        cin >> N[i] ;
    }
    solve( 1, n ) ;
    int q ;
    int l, r  ;
    cin >> q  ;
    while( q-- )
    {
        cin >> l >> r ;
        pair<int, int > ans = solve ( l, r ) ;
        cout << ans.second << endl ;
    }
    return 0 ;
}
