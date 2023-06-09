// Uses priority_queue data structure although queue data structure can be used but it is not used for complexity issues
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<int> dist(V);
        for(int i=0;i<V;i++){
            dist[i]=1e9;
        }
        dist[S]=0;
        
        priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
        
        pq.push({0,S});
        
        while(!pq.empty()){
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for(auto it : adj[node]){
                int adj_dist = it[1];
                int adj_node = it[0];
                if(adj_dist+dis<dist[adj_node]){
                    dist[adj_node] = dis + adj_dist;
                    pq.push({dist[adj_node],adj_node});
                }
            }
        }
        
        return dist;
    } 
};
