vector<vector<int>> g;
vector<int> vis, par, tmp;

class Solution
{
    public:
    long long dfs(int node, int p = -1) {
        vis[node] = 1;
        par[node] = p;
        tmp.push_back(node);
        for (auto ng : g[node]) {
            if (vis[ng] == 0) {
                long long z = dfs(ng, node);
                if (z != -1) {
                    return z;
                }
            }
            else if (vis[ng] == 1) {
                long long sum = ng;
                while (node != ng) {
                    sum += node;
                    node = par[node];
                }
                if (node == ng) {
                    return sum;
                }
                return -1;
            }
        }
        return -1;
    }
    
    long long largestSumCycle(int n, vector<int> Edge)
    {
    // code here
        long long ans = -1;
        vis = vector<int>(n);
        g = vector<vector<int>>(n);
        par = vector<int>(n);
        
        for (int i = 0; i < n; i++) {
            if (Edge[i] != -1) {
                g[i].push_back(Edge[i]);
            }
        }
        
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                ans = max(ans, dfs(i));
                for (auto j : tmp) {
                    vis[j] = 2;
                }
                tmp.clear();
            }
        }
        return ans;
    }
};
