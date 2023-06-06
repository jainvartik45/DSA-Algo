class solution{
    public:
    vector<int> rank , parent;

    DisjointSet(int n{
        rank.resize(n+1,0);
        parent.resize(n+1,0);
        for(int i=0;i<n+1;i++){
            par[i] = i;
        } 
    }
    
    int findUpar(int a){
        if(par[a] == a) return a;
        else return parent[a] = findUpar(par[a]);
    }

    void UnionByRank(int u , int v){
        int ultp_u = findUpar(u);
        int ultp_v = findUpar(v);

        if(ultp_u == ultp_v) return;
        else if(rank[ultp_u] > rank[ultp_v]){
            par[ultp_v] = ultp_u;
        }

        else if(rank[ultp_u] < rank[ultp_v]){
            par[ultp_u] = ultp_v;
        }

        else{
            par[ultp_u] = ultp_v;
            rank[ultp_v]++;
        }

    }


};