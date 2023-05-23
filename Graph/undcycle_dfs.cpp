class Solution {
  public:
  
   bool dfs(int node , int parent , vector<int> adj[] , vector<int>& vis){
      
      vis[node]=1;
      
      for(auto it : adj[node]){
          if(!vis[it]){
              if(dfs(it,node,adj,vis)) return true;
          }
          else if(it!=parent){
              return true;
          }
          
      }
      return false;
  }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        bool ans = false;
        
        vector<int> vis(V,0);
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(i,-1,adj,vis)){
                    ans = true;
                    break;
                }
            }
        }
        return ans;
    }
};