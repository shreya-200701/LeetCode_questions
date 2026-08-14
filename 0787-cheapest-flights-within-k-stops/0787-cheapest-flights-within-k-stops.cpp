class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>>graph[n];
        for(int i=0;i<flights.size();i++){
            int u = flights[i][0];
            int v = flights[i][1];
            int s = flights[i][2];

            graph[u].push_back({v,s});
        }
        queue<pair<int,pair<int,int>>>q;
        vector<int>dis(n,INT_MAX);
        q.push({src,{0,-1}});
        while(q.size()>0){
            auto it = q.front();
            int u = it.first;
            int cost = it.second.first;
            int stops = it.second.second;
            q.pop();

            for( auto edge : graph[u]){
                int v = edge.first;
                int wt = edge.second;

                if(dis[v]>cost+wt && stops+1<=k){
                    dis[v] = cost + wt;
                    q.push({v,{dis[v],stops+1}});
                }
            }

        }
        if(dis[dst]==INT_MAX){
            return -1;
        }
        return dis[dst];
    }
};