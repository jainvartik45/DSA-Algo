class Solution {
     void dfs(int node,vector<int> &vis,vector<int> adj[],vector<int> &store){
        store.push_back(node);
        vis[node]=1;
        for(auto it: adj[node]){
           if(!vis[it]) dfs(it,vis,adj,store);
        }
    }
    
  public:
    // Function to return a list containing the DFS traversal of the graph.
    
   
    
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> storedfs;
        vector<int> vis(V+1,0);
        for(int i=0;i<V;i++){
            if(!vis[i]) dfs(i,vis,adj,storedfs);
        }
        
        return storedfs;
    }
};