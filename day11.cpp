class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        int curr_max = nums[0];
        int curr_min = nums[0];
        int res = nums[0];
        
        for(int i = 1 ; i < n ; i++){
            int a = curr_max*nums[i];
            int b = curr_min*nums[i];
            curr_max = max(a,max(b,nums[i]));
            curr_min = min(a,min(b,nums[i]));
            res = max(curr_max,res);
        }
        return res;
    }
};

