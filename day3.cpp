class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.length();
        
        for(int i = n/2 ; i >= 1 ; i--){
            if(n%i == 0){
                int quo = n/i;
                string tmp = s.substr(0,i);
                string res;
                for(int j = 0 ; j < quo ; j++){
                    res += tmp;
                }
                if(res == s) return true;
            }
        }
        return false;
    }
};

