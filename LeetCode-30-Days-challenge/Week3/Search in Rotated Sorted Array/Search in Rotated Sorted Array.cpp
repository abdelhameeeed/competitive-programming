class Solution {
public:
    int targ ;
    vector< int >  num;
    int ans=-1;
    int search( vector< int > & nums , int target )
    {
        if(!nums.size()) return -1 ;
        targ=target;
        num = nums ;
        int ind = findpivot(0,nums.size()-1);
        return 0 ;
    }
    int findpivot(int l,int r)
    {
        if(r<l) return -1 ;
        if(l==r) return l ;
        mid = ( l +  r ) >> 1 ;
        if( mid < r  && num[mid] > num[mid+1] ) return mid ;
        if( mid > l && num[mid] < num[mid-1] ) return mid -1 ;
        if(num[l]>=num[mid]){
            return findpivot( l , mid - 1 ) ;
        }
        else{
            return findpivot(mid+1,r);
        }
    }


};
