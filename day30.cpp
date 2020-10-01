class Solution {
public:
    int seperate(vector<int> &nums){
        int n = nums.size();
        int j;
        for(int i = 0 ; i  < n ; i++){
            if(nums[i] > 0){
                swap(nums[i],nums[j]);
                j++;
            }
        }
        return j;
    }
    int missing(vector<int> &v, int start){
      
        
        for(int i = 0 ; i < start ; i++){
            if(abs(v[i])-1 < start && v[abs(v[i])-1] > 0){
               v[abs(v[i])-1] = -v[abs(v[i])-1]; 
            }
        }
        int i;
        for( i = 0 ; i < start ; i++){
            if(v[i] > 0) break;
        }
        if(i >= start) return start+1;
        else return i+1;
    }
    int firstMissingPositive(vector<int>& nums) {
        int start = seperate(nums);
        
        return missing(nums,start);
    }
};
