class Solution {
public:

    int find_leader(int v, vector<int> &par){
        return par[v]<0 ? v : par[v]=find_leader( par[v], par);
    }

    void merge(int u, int v, vector<int> &par){
        u=find_leader(u, par);
        v=find_leader(v, par);
        if(u==v) return;
        if(par[u]<par[v]) swap(u,v);
        par[v]+=par[u];
        par[u]=v;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int> ans(2);
        vector<int> par(n+1,-1);
        for(int i=0; i<n; i++){
            int u= edges[i][0];
            int v= edges[i][1];
            int p1=find_leader(u, par);
            int p2=find_leader(v, par);
            if(p1==p2){
                ans[0]=u;
                ans[1]=v;
            }
            else{
                merge(u,v, par);
            }

        }
        return ans;
    }
};