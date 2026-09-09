class Solution {
public:
    int lengthOfLastWord(string s) {
        int count = 0;

        for(int i = 0; i < s.length(); i++) {
            if(s[i] == ' ') {
                if(i < s.length() - 1 && s[i+1] != ' ') {
                    count = 0;
                }
            }
            else {
                count++;
            }
        }

        return count;
    }
};