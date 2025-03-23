#You are in a city that consists of n intersections numbered from 0 to n - 1 with bi-directional roads between some intersections. The inputs are generated such that you can reach any intersection from any other intersection and that there is at most one road between any two intersections.
#You are given an integer n and a 2D integer array roads where roads[i] = [ui, vi, timei] means that there is a road between intersections ui and vi that takes timei minutes to travel. You want to know in how many ways you can travel from intersection 0 to intersection n - 1 in the shortest amount of time.
#Return the number of ways you can arrive at your destination in the shortest amount of time. Since the answer may be large, return it modulo 109 + 7.

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;
        
       
        vector<vector<pair<int, int>>> adj(n);
        for (auto& road : roads) {
            int u = road[0], v = road[1], time = road[2];
            adj[u].push_back({v, time});
            adj[v].push_back({u, time});
        }

        
        vector<long long> dist(n, LLONG_MAX);  
        vector<int> ways(n, 0); 
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        
        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});  

        
        while (!pq.empty()) {
            auto [currDist, node] = pq.top();
            pq.pop();

            if (currDist > dist[node]) continue;  

            for (auto& [neighbor, time] : adj[node]) {
                long long newDist = currDist + time;

                if (newDist < dist[neighbor]) {  
                    dist[neighbor] = newDist;
                    ways[neighbor] = ways[node];
                    pq.push({newDist, neighbor});
                } else if (newDist == dist[neighbor]) {  
                    ways[neighbor] = (ways[neighbor] + ways[node]) % MOD;
                }
            }
        }

        return ways[n - 1];
    }
};
