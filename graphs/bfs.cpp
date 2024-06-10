vector<int> bfs(vector<vector<int>>& adjList, int startNode, vector<bool>& visited){
    vector<int> ans;
    queue<int> q;
    q.push(startNode);
    visited[startNode] = true;
    
    while(!q.empty()){
        int t = q.front();
        q.pop();
        ans.push_back(t);
        for(auto x: adjList[t]){
            if(!visited[x]){
                q.push(x);
                visited[x] = true;
            }
        }
    }
    
    return ans;
}