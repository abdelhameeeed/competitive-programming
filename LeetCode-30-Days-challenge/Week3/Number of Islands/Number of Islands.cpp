class Solution {
public:
    int dx[4] = {0,-1,1,0} ;
    int dy[4] = {-1,0,0,1} ;
    int n , m ;
    vector< vector < char > >  grid1;
    int numIslands( vector< vector < char > > & grid ) {
        int ans = 0 ;
        n = grid.size() ;
        if(!n) return 0    ;
        m = grid[0].size() ;
        grid1 = grid ;
        for(int i = 0 ; i < n ; i ++ ){
            for(int j = 0 ; j < m ; j ++ ){
                if( grid1[i][j] == '1' )
                {
                    ++ans ;
                    grid1[i][j] = '0' ;
                    solve( i , j  );
                }
            }
        }
        return ans ;
    }
    void solve(int i , int j  )
    {
        for(int k = 0 ; k < 4 ; k ++ )
        {
            int to_x = dx[k] + i ;
            int to_y = dy[k] + j ;
            if(isvalid(to_x,to_y) && grid1[to_x][to_y] == '1')
            {
                grid1[to_x][to_y] = '0' ;
                solve(to_x,to_y) ;
            }
        }
    }
    bool isvalid(int i , int j )
    {
        return i>=0&&i<n&&j>=0&&j<m;
    }
};
