class MinStack {
    private :
    stack<pair<int,int>>st ;
    int  minn1 = INT_MAX   ;
public:
    /** initialize your data structure here. */
    MinStack() {}
    void push( int x )
    {
        minn1 = min( minn1 , x ) ;
        st.push({x,minn1});
    }
    void pop()
    {
        st.pop() ;
        if(st.size() == 0 ) minn1 = INT_MAX ;
        else minn1 = st.top().second ;
    }
    int top()
    {
        return st.top().first ;
    }
    int getMin() {
        return st.top().second ;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
