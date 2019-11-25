#include<bits/stdc++.h>
typedef long long ll  ;
using namespace std   ;
int  dx[] = {0, 0, 1, -1 } ;
int  dy[] = {1,-1,0, 0 }   ;
char dir[] = { 'R', 'L', 'D', 'U' } ;
template< class InputIt, class Distance >
void advance( InputIt& it, Distance n );
const int sizee = 2e5 + 5 ;
struct sets
{
    set < int > S ;
};
sets alphapets[30] ;
int main()
{
    ios::sync_with_stdio() ;
    cin.tie(0) ;
    cout.tie(0);
    string s ;
    cin >> s ;
    for( int i = 0 ; i < s.size() ; i ++ )
    {
        alphapets[s[i]-'a'].S.insert( i + 1 ) ;
    }
    int q, typ, pos, l, r ;
    char e ;
    cin >> q ;
    while(q--)
    {
        cin >> typ ;
        if( typ == 1 )
        {
            cin >> pos >> e ;
            for ( int i = 0 ; i <= 26 ; i ++ )
            {
                if( alphapets[i].S.find(pos) != alphapets[i].S.end() )
                {
                    alphapets[i].S.erase(pos ) ;
                    break ;
                }
            }

            alphapets[e-'a'].S.insert( pos ) ;
        }
        if( typ == 2 )
        {
            cin >>  l >> r ;
            int ans = 0  ;
            for( int i = 0 ; i <= 26 ; i ++ )
            {
                if( alphapets[i].S.size() )
                {
                    set<int>::iterator iter  ;
                    iter = alphapets[i].S.lower_bound( l ) ;
                    if(iter != alphapets[i].S.end() )
                    {
                        if( *iter <=  r )
                            ++ ans ;
                    }
                    //cout << *iter << " " << *iter2 << endl ;
                }
            }
            cout << ans << endl ;
        }
    }
    return 0    ;
}
