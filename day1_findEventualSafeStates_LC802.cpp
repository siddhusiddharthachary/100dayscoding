class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> reverseGraph(n); 
        vector<int> outdegree(n, 0);
        
        for (int u = 0; u < n; u++) {
            for (int v : graph[u]) {
                reverseGraph[v].push_back(u);
            }
            outdegree[u] = graph[u].size();
        }
        
        queue<int> q;
        vector<bool> safe(n, false);
        
        for (int i = 0; i < n; i++) {
            if (outdegree[i] == 0) {
                q.push(i);
                safe[i] = true;
            }
        }
        
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            
            for (int prev : reverseGraph[node]) {
                outdegree[prev]--;
                if (outdegree[prev] == 0) {
                    q.push(prev);
                    safe[prev] = true;
                }
            }
        }
        
        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (safe[i]) result.push_back(i);
        }
        return result;
    }
};
