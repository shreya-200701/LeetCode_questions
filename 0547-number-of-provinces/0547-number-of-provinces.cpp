class Solution {
public:
    class disjointunion{
        public:
        int v;
        vector<int>par;
        vector<int>rank;
        disjointunion(int n){
            this->v = n;
            for(int i=0;i<v;i++){
                par.push_back(i);
                rank.push_back(0);
            }
        }
        int find(int x){
            if(par[x] == x){
                return x;
            }
            return par[x] = find(par[x]);
        }
        void unions(int a, int b){
            int parA = find(a);
            int parB = find(b);
            if(parA == parB){
                return;
            }
            else if(rank[parA]==rank[parB]){
                par[parB] = parA;
                rank[parA]++;
            }
            else if(rank[parA]>rank[parB]){
                par[parB]=parA;
            }else{
                par[parA]=parB;
            }
        }
    };
    int findCircleNum(vector<vector<int>>& isConnected) {
        int count = 0;
        int n = isConnected.size();
        disjointunion dis(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n-1;j++){
                if(isConnected[i][j]==1){
                    dis.unions(i,j);
                }
            }
        }
        for(int i = 0;i< n ;i++){
            if(dis.find(i)==i){
                count++;
            }
        }
        return count;
    }
};