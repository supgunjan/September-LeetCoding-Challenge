class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int n = nums.size();
        if(n == 1 || k == 0){
            return false;
        }
 
        multiset<long> s;
 
        for(int i = 1; i < min(n, k + 1); i++){
            s.insert(nums[i]);    
        }
        cout << s.size();
        for(int i = 0; i < n; i++){
            auto idx = s.lower_bound((long)nums[i] - (long)t);
            if(idx != s.end() && *idx <= (long)nums[i] + (long)t){
                return true;
            }
 
            if(s.size() > 0)
                s.erase(s.find(nums[i + 1]));
 
            int j = i + k + 1;
            if(j < n){
                s.insert(nums[j]);
            }                    
        }
        return false;
    }
};
