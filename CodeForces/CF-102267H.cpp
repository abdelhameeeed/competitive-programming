/* https://codeforces.com/gym/102267/problem/H */
#include<iostream>
#include<bits/stdc++.h>
#include<bits/stdc++.h>
typedef long long ll  ;
using namespace std   ;
int  dx[] = {0, 0, 1, -1 } ;
int  dy[] = {1,-1,0, 0 }   ;
char dir[] = { 'R', 'L', 'D', 'U' } ;
const float pii = 3.14159265 ;
int main()
{
    float v, s ;
    cin >> v >> s ;
    s = float ( s / 2 ) ;
    float whole_ang = ( v - 2 ) * 180 ;
    float each_ = whole_ang / v  ;
    each_ = float(each_ / 2) ;
    float ver_ang = float( ( 180 - ( each_ * 2 ) ) / 2 ) ;
    float anss_ = float( s / sin(ver_ang*pii / 180 )  ) ;
    cout <<fixed << setprecision(6) << pii * ( anss_ * anss_ ) << endl ;
    return 0  ;
}
