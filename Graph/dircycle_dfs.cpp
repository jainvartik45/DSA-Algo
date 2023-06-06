class Solution {
  public:
  bool dfs(vector<int> adj[],vector<int>& vis,int node,vector<int>& path_vis){
        vis[node] = 1;
        path_vis[node] = 1;
        
        for(auto it : adj[node]){
            if(!vis[it]){
                if(dfs(adj,vis,it,path_vis)) return true;
            }
            else if(path_vis[it]) return true;
        }
        path_vis[node] = 0;
        return false;
    }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> vis(V,0),path_vis(V,0);
        
        bool ans = 0;

        for(int i = 0;i<V;i++){
           
            if(!vis[i]){
                if(dfs(adj,vis,i,path_vis)){
                    ans=1;
                    break;
                }
            }
        }
        return ans;
    }
};