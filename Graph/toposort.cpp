// first , we need to find the indegree because we need to find the nodes from where the graph is originating
// we always push a node with indegree = 0 to the queue with the the process of applying bfs
// tpsort is generally a process of sorting nodes using the indegree values.
class Solution
{
	public:

	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> indegree(V,0);
	    
	    for(int i=0;i<V;i++){
    	    for(auto it : adj[i]){
    	        
    	            indegree[it]++;
    	        
    	    }
	    } 
	  
	    
	    queue<int> q;
	    
	    for(int i=0;i<V;i++){
	        if(indegree[i]==0){
	            q.push(i);
	            
	        } 
	    }
	    
	    
	    vector<int> ans;
	    
	    while(!q.empty()){
	        int node = q.front();
	        
	        q.pop();
	        
	        ans.push_back(node);
	        
	        
    	        for(auto it : adj[node]){
    	            indegree[it]--;
    	            if(indegree[it]==0){
    	                q.push(it);
    	                
    	            }
    	        }
	        
	    }
	    
	    
	    return ans;
	}
};
