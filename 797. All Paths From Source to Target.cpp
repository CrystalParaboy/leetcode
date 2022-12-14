class Solution {
public:
void dfs(vector<vector<int>>& graph, vector<vector<int>>& result, vector<int> path, int src, int dst) {
    path.push_back(src);
    if(src == dst) {
        result.push_back(path);
        return;
    }

    for(auto node : graph[src])
        dfs(graph, result, path, node, dst);
}
vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    vector<vector<int>> paths; vector<int> path; 
    stack<int> st;
    int nodes = graph.size();
    dfs(graph, paths, path, 0, nodes-1);
    return paths;
}
    
};
