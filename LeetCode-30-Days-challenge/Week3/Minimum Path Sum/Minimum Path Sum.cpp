class Solution {
public:
    int n,m;
    int memo[(int)1e3+5][(int)1e3+5];
    vector<vector<int>> grid1;
    int minPathSum(vector<vector<int>>& grid) {
        n=grid.size();
        if(!n)return 0 ;
        m=grid[0].size() ;
        memset(memo,-1,sizeof(memo));
        grid1=grid ;
        return solve(0,0);
    }
    int solve(int i,int j)
    {
        if(i==n-1&&j==m-1) { return grid1[i][j] ; }
        int &ret = memo[i][j] ;
        if(~ret) return ret ;
        ret = 1e9 ;
        if(i+1<=n-1) { ret = solve(i+1,j); }
        if(j+1<=m-1) { ret=min( ret ,solve(i,j+1)); }
        ret = grid1[i][j] + ret ;
        return ret ;
    }
};
