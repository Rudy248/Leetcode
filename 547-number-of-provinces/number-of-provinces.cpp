class Solution {
public:

    void Bfs(int node, vector<bool> &vis, vector<vector<int>>& isConnected, int n){
        vis[node]=true;
        queue<int> q;
        q.push(node);
        while(!q.empty()){
            int cur=q.front();
            q.pop();
            for(int i=0; i<n; i++){
                if(isConnected[cur][i]==1){
                    if(!vis[i]){
                        vis[i]=true;
                        q.push(i);
                    }
                }
            }
        }
    }   
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n= isConnected.size();
        vector<bool>vis(n, false);
        int k=0;
        for(int i=0; i<n; i++){
            if(vis[i]){
                continue;
            }
            else{
                k++;
                Bfs(i, vis, isConnected, n);
            }
        }
        return k;
    }
};