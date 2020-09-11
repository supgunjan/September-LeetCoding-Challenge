class Solution {
public:
    string getHint(string secret, string guess) {
        int h1[10] = {0};
        int h2[10] = {0};
        int cnt = 0;
        int same = 0;
        string res;
        int n = secret.length();
        for(int i = 0 ; i < n ; i++){
            h1[secret[i]-'0']++;
            h2[guess[i]-'0']++;
        }
        for(int i = 0 ; i < n ; i++){
            if(secret[i] == guess[i]){
                h1[secret[i]-'0']--;
                h2[secret[i]-'0']--;
                same++;
            }
        }
      
        for(int i = 0 ; i < 10 ; i++){
            if(h1[i] > 0){
                cnt += min(h1[i],h2[i]);
            }
        }
     
        res += to_string(same) + 'A' + to_string(cnt) + 'B';
        
        return res;
    }
};

