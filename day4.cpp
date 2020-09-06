class Solution {
public:
    vector<int> partitionLabels(string S) {
        int n = S.length();
        if(n == 0) return {};
        int h[26] = {0};
        vector<int> res;
        for(int i = 0 ; i < n ; i++){
            h[S[i]-'a'] = i;
        }
        
        int left = 0;
        int right = 0;
        for(int i = 0 ; i < n ; i++){
            right = max(right,h[S[i]-'a']);
            if(i == right){
                res.push_back(right-left+1);
                left = right+1;
            }
        }
        return res;
    }
};

