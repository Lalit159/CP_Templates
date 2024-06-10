// In some questions, we may have to compromise on union by 
// rank-size and/or path-compression. BE CAREFUL

class DisjointSet {
    vector<int> rank, parent, size;
  public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) { // Find ultimate parent of the set 
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]); // PATH COMPRESSION
    }

    void union(int u, int v){ // Without rank or size
        u = findUPar(u);
        v = findUPar(v);
        if(u!=v) parent[v] = u;
    }

    void unionByRank(int u, int v) { // Union by rank
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) { // Union by size
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

