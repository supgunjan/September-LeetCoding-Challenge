class Solution {
public:
    vector<vector<int>> res;
    void helper(vector<int> &tmp, int k, int n,int start){
        if(tmp.size() == k && n == 0){
            res.push_back(tmp);
        }
        for(int i = start ; i <= 9 ; i++){
            tmp.push_back(i);
            helper(tmp,k,n-i,i+1);
            tmp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> tmp;
        helper(tmp,k,n, 1);
        return res;
    }
