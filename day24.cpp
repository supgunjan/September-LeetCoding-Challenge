class Solution {
public:
    char findTheDifference(string s, string t) {
        char tmp = s[0];
        int n = s.length();
        for(int i = 1 ; i < n ; i++){
            tmp ^= s[i];
        }
        n = t.length();
        for(int i = 0 ; i < n ; i++){
            tmp ^= t[i];
        }
        return tmp;
    }
};
