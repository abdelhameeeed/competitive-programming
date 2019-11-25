#include<bits/stdc++.h>
typedef long long ll  ;
using namespace std   ;
const long long INF64 = ( long long)(1e18) + 100 ;
const int sizee = 4e5 + 5   ;
int head[sizee], to[sizee], nxt[sizee], ne, vis[sizee] ;
int n, m ;
vector< int > vv ;
vector< pair < int , int > > pairs__  ;
void init()
{
    memset( head, -1 , (n + 1 ) * sizeof(int) ) ;
    ne = 0  ;
}
void adD_edge(int f, int t )
{
    nxt[ne] = head[f]  ;
    to[ne] = t ;
    head[f] = ne ++ ;
}
void bi( int a, int b )
{
    adD_edge(a, b) ;
    adD_edge(b, a ) ;
}
void solve(int uu)
{
    vis[uu] = 1 ;
    vv.push_back(uu) ;
    for(int e = head[uu], v ; ~e ; e = nxt[e] )
    {
        v = to[e] ;
        if( !vis[v] )
        {
            solve( v ) ;
        }
    }
}
int main()
{
    ios::sync_with_stdio() ;
    cin.tie(0)   ;
    cout.tie(0)  ;
    cin >> n >> m ;
    init() ;
    int u, v ;
    for(int i = 1 ; i <= m  ; i ++ )
    {
        cin >> u >> v ;
        bi( u, v ) ;
    }
    for( int i = 1 ; i <= n ; i ++ )
    {
        if( !vis[i] )
        {
            vv.clear() ;
            solve(i)   ;
            if( vv.size() == 1 )
            {
                pairs__.push_back( { i , -1 } ) ;
            }
            else
            {
                sort( vv.begin() , vv.end() ) ;
                pairs__.push_back({ vv[0] , vv[ vv.size()-1] } ) ;
            }
        }
    }
    sort(pairs__.begin() , pairs__.end() ) ;
    int ans = 0 ;
    /*
    for(int i = 0 ; i < pairs__.size() ; i ++ )
    {
        cout << pairs__[i].first << '\t' << pairs__[i].second << '\n'  ;
    }
    */
    int max_right = pairs__[0].second ;
    for(int i = 1 ; i < pairs__.size() ; i++ )
    {
        max_right = max( max_right , pairs__[i].second ) ;
        if( pairs__[i].second == -1 )
        {
            if(pairs__[i].first < max_right )
                ++ ans ;
        }
        else
        {
            if( pairs__[i].first > pairs__[i-1].first  )
            {
                if( pairs__[ i - 1 ].second != -1 )
                {
                    ans += pairs__[i].first < pairs__[i-1].second ;
                }
            }
            else if ( pairs__[i].first > pairs__[i-1].second  )
            {
                if( pairs__[i].first < max_right )
                    ++ ans ;
            }
        }
    }
    cout << ans << '\n' ;
    return 0 ;
}

