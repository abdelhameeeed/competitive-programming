/* https://codeforces.com/contest/1244/problem/D */
#include<bits/stdc++.h>
typedef long long ll  ;
using namespace std   ;
const long long INF64 = (long long)(1e18) + 100 ;
const int sizee = 1e5 + 5   ;
int N[sizee] ;
vector<int>vv[sizee] ;
int child[sizee]   ;
ll grid[5][sizee]  ;
ll ans = 1e18 ;
int n ;
int colors[sizee] ;
string S ;
ll H = 0 ;
void solve( int ind , int prev_par , int cur_node = 1 )
{
    H = (ll) H + grid[S[ind]-48][cur_node ] ;
    for( int i = 0 ; i < vv[cur_node].size() ; i ++ )
    {
        int NOde_ = vv[cur_node][i] ;
        if( NOde_ == prev_par ) continue ;
        solve( ( ind + 1 ) % 3 ,  cur_node , NOde_ ) ;
    }
}
void solve2( int ind , int prev_par , int cur_node = 1 )
{
    colors[cur_node] = S[ind]-48 ;
    for( int i = 0 ; i < vv[cur_node].size() ; i ++ )
    {
        int NOde_ = vv[cur_node][i] ;
        if( NOde_ == prev_par )
            continue ;
        solve2( ( ind + 1 ) % 3 ,  cur_node , NOde_ ) ;
    }
}
int main()
{
    ios::sync_with_stdio() ;
    cin.tie(0)   ;
    cout.tie(0)  ;
    cin >> n ;
    for(int i = 1 ; i <= 3 ; i ++ )
    {
        for( int j = 1 ; j <= n ; j ++ )
        {
            cin >> grid[i][j] ;
        }
    }
    int u , v ;
    for( int i = 1 ; i < n ; i ++ )
    {
        cin >> u >> v ;
        vv[u].push_back(v);
        vv[v].push_back(u);
        ++ child[u] ;
        ++ child[v] ;
    }
    int root_ = 0 ;
    for( int i = 1 ; i <= n ; i ++ )
    {
        if( child[i] == 1 ) root_ = i  ;
        if( child[i] > 2  )
        {
            cout << -1 << endl ;
            exit(0) ;
        }
    }
    string arr[] = { "123" , "132" ,  "231" , "213" , "312" , "321" } ;
    int ind = -1 ;
    for( int i = 0 ; i < 6 ; i ++ )
    {
        H = 0 ;
        S  = arr[i] ;
        solve( 0 , -1 , root_ ) ;
        if ( ans >  H )
        {
            ans = H ;
            ind = i ;
        }
    }
    cout << ans << endl ;
    S = arr[ind] ;
    solve2( 0 , -1 , root_ ) ;
    for(int i = 1 ; i <= n ; i ++ )
    {
        cout << colors[i] << " " ;
    }
    return 0     ;
}
