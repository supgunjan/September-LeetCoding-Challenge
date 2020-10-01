const int K = 30;
 
struct trie{
    trie* nxt[K];
    bool isEnd;
};
 
trie* newNode(){
    trie* tmp = new trie();
    for(int i = 0; i < K; i++){
        tmp->nxt[i] = NULL;            
    }
    tmp->isEnd = false;
    return tmp;
}
 
void insert(trie* root, string &s){
    trie* tmp = root;
    int n = s.size();
 
    for(int i = 0; i < n; i++){
        int idx = s[i] - 'a';
        if(tmp->nxt[idx] == NULL){
            tmp->nxt[idx] = newNode();            
        }
        tmp = tmp->nxt[idx];
    }
    tmp->isEnd = true;
}
 
bool solve(int i, int n, trie* root, string &s, vector<int> &dp){
 
    if(i == n) return true;                   
 
    if(dp[i] == 0) return false;
 
    int idx = i;
    trie* tmp = root;
 
    while(i < n && tmp->nxt[s[i] - 'a']){
        tmp = tmp->nxt[s[i] - 'a'];
        if(tmp->isEnd && solve(i + 1, n, root, s, dp)) return true;
        i++;
    }
 
    dp[idx] = 0;
    return false;
}
 
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
 
        trie* root = newNode();
 
        for(auto &word : wordDict){
            insert(root, word);
        }        
 
        int n = s.size();
 
        vector<int> dp(n, -1);
 
 
        return solve(0, n, root, s, dp);
    }
};
