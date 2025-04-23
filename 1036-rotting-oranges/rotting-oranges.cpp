class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        
        queue<int> q;   
        vector<vector<int>> time (m, vector<int> (n,0));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==2){
                    q.push((i*n)+j);
                    time[i][j]=0;
                }
            }
        }
       vector<pair<int, int>> dir {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};

        while(!q.empty()){
            int cur = q.front();
            q.pop();
            int x=cur/n;
            int y=cur%n;
            for(auto [dx, dy]: dir){
                if((x+dx)<m && (x+dx)>=0 && (y+dy)<n && (y+dy)>=0 && grid[x+dx][y+dy]==1){
                    q.push(((x+dx)*n)+(y+dy));
                    grid[x+dx][y+dy]=2;
            time[x+dx][y+dy]=time[x][y]+1;
                }
            }
            }
        int max_time=-1; 
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1){
                    return -1;
                }
                else if(time[i][j]>max_time){
                    max_time=time[i][j];
                }
            }
        }
        return max_time;
        }
};