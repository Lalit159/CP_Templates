void dfs_helper(int i, vector<bool>& visited, vector<int>& ans, vector<vector<int>>& adj){
    visited[i] = true;
    ans.push_back(i);
    for(auto x: adj[i]){
        if(!visited[x])
            dfs_helper(x, visited, ans, adj);
    }
}
  
vector<int> dfs(int V, vector<vector<int>>& adj) {
    vector<bool> visited(V, false);
    vector<int> ans;
    dfs_helper(0, visited, ans, adj);
    return ans;
}