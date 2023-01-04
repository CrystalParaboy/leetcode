class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<int>> visited(grid.size(),vector<int>(grid[0].size(),0));
        int res=0;
        int dir[4][2]={0,1,0,-1,1,0,-1,0};
        queue<pair<int,int>> que;
        auto bfs=[&](int x, int y){
            visited[x][y]=1;  
            que.push({x,y});
            //cout<<"bfs begin"<<endl;
            while(!que.empty()){
                pair<int,int> cur=que.front(); que.pop();
                int curx=cur.first;
                int cury=cur.second;
                for(int i=0;i<4;i++){
                    int nextx=curx+dir[i][0];
                    int nexty=cury+dir[i][1];
                    if(nextx<0||nexty<0||nextx>=grid.size()||nexty>=grid[0].size()) continue;
                    if(grid[nextx][nexty]=='1'&&visited[nextx][nexty]==0) {
                        visited[nextx][nexty]=1;
                        que.push({nextx,nexty});
                    }
                }
            }
        };
        for(int x=0;x<grid.size();x++){
            for(int y=0;y<grid[0].size();y++){
                if(visited[x][y]==1) continue;
                if(grid[x][y]=='1'){
                    res++;
                    bfs(x,y);
                }
            }
        }

        for(int k=0; k<grid.size(); k++){
		    for(int x=0; x<grid[0].size(); x++){
				 cout<<visited[k][x]<<" ";
				}
				cout<<endl;
		}
        return res;
    }
};
