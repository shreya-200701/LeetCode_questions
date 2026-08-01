class Solution {
public:
    bool dfs(int curr,vector<bool>&vis,vector<bool>&recpath,vector<vector<int>>& prerequisites){
        vis[curr] = true;
        recpath[curr] = true;
        vector<int>l={};
        for(int i=0;i<prerequisites.size();i++){
            if(curr == prerequisites[i][1]){
                l.push_back(prerequisites[i][0]);
            }
        }
        for(int x:l){
            if(!vis[x]){
                if(!dfs(x,vis,recpath,prerequisites)){
                    return false;
                }
            }else if(recpath[x]){
                return false;
            }
        }
        recpath[curr] = false;
        return true;

    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool>vis(numCourses,false);
        vector<bool>recpath(numCourses,false);
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(!dfs(i,vis,recpath,prerequisites)){
                    return false;
                }
            }
        }
        return true;
    }
};