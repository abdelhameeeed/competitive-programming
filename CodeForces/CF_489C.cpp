/* https://codeforces.com/contest/489/problem/C */
#include<bits/stdc++.h>
#define  print  cout<<
#define FRD freopen("in.txt", "r", stdin)
#define FWR freopen("out.txt", "w", stdout)
#define PI 3.14159265
const int OO = 0x3f3f3f3f                        ;
typedef long long ll                             ;
using namespace std                              ;
void fastt()                                     ;
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
int m, s ;
int mem[101][901][2];
vector<int>v;
bool solve( int si, int sum, bool f )
{
    if( si == m + 1 )
        return sum == s ;
    int &ret = mem[si][sum][f];
    if(~ret)
        return ret ;
    ret = 0 ;
    for( int i = 0 ; i <= 9 ; i ++ )
    {
        if( i == 0 && !f )
            continue        ;
        ret|=solve( si + 1, sum + i, 1 ) ;
    }
    return ret ;
}
bool solve1( int si, int sum, bool f )
{
    if( si == m + 1 )
        return sum == s ;
    int &ret = mem[si][sum][f];
    if(~ret)
        return ret ;
    ret = 0 ;
    for( int i = 9 ; i >=0  ; i -- )
    {
        if( i == 0 && !f )
            continue        ;
        ret|=solve( si + 1, sum + i, 1 ) ;
    }
    return ret ;
}
void build1(int si, int sum, bool f)
{
    if( si == m + 1 )
        return ;
    bool r = false ;
    for( int i = 9 ; i >= 0 ; i -- )
    {
        if( i == 0 && !f )
            continue ;
        r = solve1( si + 1, sum + i, 1 ) ;
        if( r )
        {
            v.push_back(i);
            build1( si + 1, sum + i, 1 ) ;
            break   ;
        }
    }
}
void build(int si, int sum, bool f)
{
    if( si == m + 1 )
        return ;
    bool r = false ;
    for( int i = 0 ; i <= 9 ; i ++ )
    {
        if( i == 0 && !f )
            continue ;
        r = solve( si + 1, sum + i, 1 ) ;
        if( r )
        {
            v.push_back(i);
            build( si + 1, sum + i, 1 ) ;
            break   ;
        }
    }
}
int main()
{
    fastt() ;
    memset(mem, -1, sizeof(mem));
    cin >> m >> s     ;
    if(m == 1 && s == 0 )
    {
        print 0 << ' ' << 0 << endl ;
        return 0 ;
    }
    if(!solve(1,0,0)   )
    {
        print -1 <<' '<<-1 << endl ;
    }
    else
    {
        build(1, 0, 0 ) ;
        for( int i = 0 ; i < v.size() ; i ++ )
        {
            print v[i] ;
        }
        print " " ;
        v.clear() ;
        memset(mem, -1, sizeof(mem));
        solve1(1,0,0);
        build1(1,0,0);
        for(int i = 0 ; i < v.size() ; i ++ )
        {
            print v[i];
        }
    }
}
void fastt()
{
    ios::
    sync_with_stdio(false),
                    cin.tie(0),
                    cout.tie(0) ;
}
/*
string s ;
ll mem[100][100];
ll solve(int i, int j)
{
    if( i == j )
        return 1  ;
    if( i + 1 == j )
    {
        return 2 + ( s[i] == s[j] ) ;
    }
    ll &ans = mem[i][j] ;
    if( ~ans )
        return ans ;
        ans = 0 ;
    if(s[i]==s[j])
    {
        ans = 1 + solve( i + 1 , j - 1 ) ;
    }
    ans = ans + solve( i + 1 , j )  ;
    ans = ans + solve(i , j - 1 ) ;
    ans -= solve( i + 1 , j - 1 ) ;
    return ans ;
}
*/
