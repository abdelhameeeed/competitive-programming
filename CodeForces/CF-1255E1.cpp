#include<bits/stdc++.h>
typedef long long ll  ;
using namespace std   ;
const long long INF64 = ( long long)(1e18) + 100 ;
const int sizee = 4e5 + 5   ;
int N[sizee] ;
int main()
{
    ios::sync_with_stdio() ;
    cin.tie( 0  )   ;
    cout.tie( 0 )   ;
    int n ;
    cin >>  n ;
    ll SUM = 0 ;
    for(int i = 1 ; i <= n ; i ++ )
    {
        cin >> N[i] ;
        SUM += N[i] ;
    }
    vector< int > v ;
    for( int i = 2 ; i <= SUM ; i ++ )
    {
        if( SUM % i == 0 )
            v.push_back( i ) ;
    }
    ll result = 1e18 ;
    for( int i = 0 ; i < v.size() ; i ++ )
    {
        int cur_K = v[i] ;
        vector< int > pos__ ;
        int Cur_sum = 0     ;
        ll ans = 0 ;
        for( int j = 1 ; j <= n ; j ++ )
        {
            if( N[j] == 1 )
            {
                if( Cur_sum < cur_K )
                {
                    Cur_sum += 1 ;
                    pos__.push_back( j ) ;
                }
                if( Cur_sum == cur_K )
                {
                    int med = pos__.size() / 2 ;
                    for( int kk = 0 ; kk < pos__.size() ; kk ++ )
                    {
                        ans += abs( pos__[kk] - pos__[med] ) ;
                    }
                    pos__.clear() ;
                    Cur_sum = 0   ;
                }
            }
        }
        result = min( result, ans ) ;
    }
    if( result == 1e18 )
    {
        cout << -1 << '\n' ;
    }
    else
        cout << result << '\n' ;
    return 0 ;
}

