/* https://codeforces.com/contest/1176/problem/D */
#include<iostream>
#include<bits/stdc++.h>
#define FRD freopen("in.txt", "r", stdin)
#define FWR freopen("out.txt", "w", stdout)
typedef long long ll    ;
using namespace std      ;
const int sizee = 3e6 + 13 ;
int N[sizee] ;
int is_prime[sizee] ;
vector< int > prime__ ;
unordered_map< int, int > vis ;
unordered_map< int, int > div_ ;
void pre__()
{
    for( int i = 2 ; i < sizee  ; i ++ )
    {
        if( !is_prime[i] )
        {
            prime__.push_back(i) ;
            for( ll j = (ll) i * i ; j < sizee ; j = ( ll )j +  i  )
            {
                is_prime[j] = true ;
            }
        }
    }

}
int great_div( int x )
{
   for(int i = 2 ; i <= x / i ; i ++ )
   {
       if( x % i == 0 )
       {
           return x / i ;
       }
   }
}
int main()
{
    int n ;
    cin >>  n ;
    pre__()   ;
    for( int i = 1 ; i <= n * 2 ; i ++ )
    {
        cin >> N[i]   ;
        ++ vis[N[i]]  ;
    }
    sort( N + 1, N + ( 2 * n ) + 1,  greater<int> () ) ;
    vector< int > res ;
    for( int i = 1 ; i <= 2 * n ; i ++ )
    {
         if( !is_prime[N [i] ] && vis[ N[ i ] ] && N[i] <= 199999 )
        {
            if( vis[  prime__[N[i]-1 ]     ] )
            {
                --vis[N[i]] ;
                --vis[  prime__[N[i]-1 ]     ] ;
                res.push_back(N[i] ) ;
            }
        }
        else if( is_prime[  N[i] ] &&  vis[    N[i]   ] )
        {
            res.push_back( N[i] ) ;
            --vis[N[i]] ;
            --vis[ great_div( N[ i ] )  ] ;
        }
    }
    for(int i = 0 ; i < res.size() ; i ++ )
    {
        cout << res[i] <<" " ;
    }
    return 0  ;
}
