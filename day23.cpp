class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int n = gas.size();
        int prevsm = 0;
        int ans = 0;
        int total = 0;
        for(int i = 0 ; i < n ; i++ ){
            total += gas[i]-cost[i];
            if(gas[i]+prevsm >= cost[i]){
                prevsm += gas[i]-cost[i];
            }
            else{
                prevsm = 0;
                ans = (i+1)%n;
            }
        }
        return (total >= 0 ? ans : -1);
    }
};
