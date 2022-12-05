class LockingTree {
    
    vector<int> list;
    vector<vector<int>> adj;
    vector<int> par;
public:
    LockingTree(vector<int>& parent) {
        par=parent;
        list.resize(par.size(),-1);
        adj.resize(par.size());
        for (int i = 0; i < par.size(); i++) {
            if (par[i] != -1) {
                adj[par[i]].push_back(i);
            }
        }
    }
    
    bool lock(int num, int user) {
        if (list[num] != -1) return false;
        list[num] = user;
        return true;
    }
    
    bool unlock(int num, int user) {
        if (list[num] != user) return false;
        list[num] = -1;
        return true;
    }

    bool checkdes(int x){
        bool ans=false;
        if(list[x]!=-1){
            ans=true;
            list[x]=-1;
        }
        for(int it: adj[x])
            ans|=checkdes(it);
        
        return ans;
            
    }
    bool check_locked_par(int x) {
        if (x == -1) return false;
        return list[x] != -1 ? true : check_locked_par(par[x]);
    }
    bool upgrade(int num, int user) {
        if (!check_locked_par(num) && checkdes(num)) {
            list[num] = user;
            return true;
        }
        
        return false;
        
    }
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */
