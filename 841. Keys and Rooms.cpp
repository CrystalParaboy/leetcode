class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        stack<int> st;
        int temp,num=1;
        vector<bool> visited(rooms.size(),0); visited[0]=1;
        for(auto room:rooms[0]) {
            if(room==0) continue;
            st.push(room); num++; visited[room]=1;} 
        if(st.empty()&&rooms.size()<=1) return true;
        
        while(!st.empty()){
            if(num==rooms.size()) return true;
            temp=st.top();
            st.pop();
            if(rooms[temp].size()==0) continue;
            for(auto room:rooms[temp]){
                if(visited[room]) continue;
                visited[room]=1;
                st.push(room);
                num++;
            }
        }
        cout<<num<<" "<<rooms.size();
        return false;
    }
};
