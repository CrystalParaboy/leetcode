class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int len=grid.size(), 
            bor=grid[0].size(), 
            res=0;
        vector<vector<int>> v(len, vector<int>(bor, 0));
        shared_ptr<queue<vector<int>>> que=make_shared<queue<vector<int>>>();
        int dir[4][2]={1,0,-1,0,0,1,0,-1};
        //bfs
        auto bfs=[&](int &x, int &y){
            int temp=1;
            que->push({x, y});
            v[x][y]=1;
            while(!que->empty()){
                int curx= que->front()[0],
                    cury= que->front()[1],
                    nextx, nexty;
                que->pop();
                for(int i=0;i<4;i++){
                    nextx= curx + dir[i][0];
                    nexty= cury + dir[i][1];
                    if(nextx<0 || nexty<0 || nextx>= len || nexty>=bor) continue;
                    if(v[nextx][nexty]==0 && grid[nextx][nexty]==1){
                        ++temp;
                        v[nextx][nexty]=1;
                        que->push({nextx, nexty});
                    }
                }
            }
            res=max(temp, res);
            return;
        };

        for(int i=0;i<len;i++){
            for(int j=0;j<bor;j++){
                if(grid[i][j]==1 && v[i][j]==0) bfs(i,j);
            }
        }
        return res;
    }
};
