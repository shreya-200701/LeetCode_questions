class Solution {
public:
    int dis(vector<vector<int>> &points, int p1, int p2){
        return abs(points[p1][0]-points[p2][0]) + abs(points[p1][1] - points[p2][1]);
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        int ans = 0;
        vector<bool>vis(points.size(),false);
        pq.push({0,0});
        while(pq.size()>0){
            auto it = pq.top();
            int wt = it.first;
            int idx = it.second;
            pq.pop();
            if(!vis[idx]){
                vis[idx] = true;
                ans = ans + wt;
                for(int i=0;i<points.size();i++){
                    if(!vis[i]){
                        pq.push({dis(points,i,idx),i});
                    }
                }
            }

        }
        return ans;
    }
};