class Solution {
public:
    int lengthOfLastWord(string s) {
        if(s.length() == 0) return 0;
        int i = s.length()-1;
        string res;
        bool flag = false;
        while(i >= 0){
            if(s[i] != ' '){
              flag = true; 
              res = res+s[i];
            } 
            if(flag && s[i] == ' ') break;
            i--;
        }
        return res.length();
    }
};
