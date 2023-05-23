class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        queue<pair<int,int>> q;
        vector<int> vis(V,0);
        bool b = false;
        for(int i=0;i<V;i++){
            
            if(!vis[i]) q.push({i,-1});
            vis[i]=1;
            
            while(!q.empty()){
                int node = q.front().first;
                int parent = q.front().second;
                
                q.pop();
                
                for(auto it : adj[node]){
                    if(it!=parent){
                        if(!vis[it]){
                            vis[it]=1;
                            q.push({it,node});
                        }
                        else{
                            b = true;
                            break;
                        }
                    }
                }
            }
        }    
        return b;
    }
};