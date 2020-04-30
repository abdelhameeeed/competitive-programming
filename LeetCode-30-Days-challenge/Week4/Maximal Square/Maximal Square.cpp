class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix)
    {
        int n = matrix.size() ;
        if(!n) return 0 ;
        int m = matrix[0].size() ;
        vector<vector<int>> matrix1(n , vector<int>(m));
        int maxx = 0 ;
        for(int i = 0 ; i < n ; i ++ ){
            for(int j = 0 ; j < m ; j ++ ){
                matrix1[i][j] = matrix[i][j]-48;
                maxx = max( matrix1[i][j] , maxx  ) ;
            }
        }
        for(int i = 1 ; i < n ; i ++ )
        {
                 for(int j = 1 ; j < m ; j ++ )
                 {
                    if(matrix1[i][j]!=0)
                    {
                        matrix1[i][j] = min ( min( matrix1[i][j-1] , matrix1[i-1][j]   ) , matrix1[i-1][j-1] ) + 1 ;
                        if(maxx < matrix1[i][j] ) maxx = matrix1[i][j] ;
                    }
                 }
        }
        return maxx * maxx  ;
    }
};
