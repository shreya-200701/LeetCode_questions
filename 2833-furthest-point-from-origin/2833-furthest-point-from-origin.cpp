class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int count  = 0;
        int left = 0;
        int right = 0;
        for(int i=0;i<moves.length();i++){
            if(moves[i]=='L'){
                left++;
            }else if(moves[i]=='R'){
                right++;
            }
        }
        for(int i=0;i<moves.length();i++){
            if(moves[i]=='L'){
                count--;
            }else if(moves[i]=='R'){
                count++;
            }else{
                if(left>right){
                    count--;
                }else{
                    count++;
                }
            }
        }
        return abs(count);
    }
};