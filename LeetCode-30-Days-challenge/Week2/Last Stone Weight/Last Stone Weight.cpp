class Solution {
public:
    int lastStoneWeight(vector<int>& stones)
    {
        priority_queue<int>q(stones.begin(),stones.end());
        while(q.size()>1){
            int f = q.top();
            q.pop();
            int s = q.top();
            q.pop();
            if(f!=s) q.push(f-s);
        }
        if(q.size()) return q.top() ;
        else return  0 ;
    }
};
