class Solution {
public:
    static bool comp(int a, int  b){
        
        return ((to_string(a)+to_string(b)) > (to_string(b)+to_string(a)));
    }
    string largestNumber(vector<int>& nums)
    {
        sort(nums.begin(),nums.end(),comp);
        if(to_string(nums[0]) == "0") return "0";

        string res;
        for(int i = 0 ; i < nums.size() ; i++){
            res += to_string(nums[i]);           
        }
        return res;
    }
};
