/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int x, int y);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {

        vector<int> dim = binaryMatrix.dimensions() ;
        int n = dim[0]   ;
        if(!n) return -1 ;
        int m = dim[1]   ;
        int ans = INT_MAX  ;
        int i = n - 1 , j = m - 1 ;
        while( i >= 0 && j >= 0 )
        {
             if(binaryMatrix.get(i,j)==0) --i ;
            else --j;
        }
        return j != m-1 ? j + 1 : -1 ;
    }
};
