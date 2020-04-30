class FirstUnique {
public:
    vector< int > numbers ;
    unordered_map<int,int>vis;
    queue<int>Q;
    FirstUnique(vector<int>& nums) {
        numbers = nums ;
        for(auto i : numbers){
            vis[i] = vis[i]+1;
        }
        for(auto i : numbers ){
            if(vis[i] == 1 ){
                Q.push(i);
            }
        }
    }
    int showFirstUnique()
    {

        while(Q.size()){
            if(vis[Q.front()] == 1 ){
                return Q.front();
                break ;
            }
            else
            {
                Q.pop();
            }
        }
        return -1 ;
    }
    void add(int value) {
        ++vis[value];
        if(vis[value]==1) Q.push(value);
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */
