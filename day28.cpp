class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
 
        int ans = 0;
        int cur_product = 1;
 
        int i = 0, j = 0;
        while(j < n){
            cur_product *= nums[j];
 
            while(i < j && cur_product >= k){
                cur_product /= nums[i++];
            }
 
            if(cur_product < k)
                ans += j - i + 1;
            j++;
        }
        return ans;
    }
};
