class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int n = timeSeries.size();
        if(n == 1) return duration;
        int cnt = 0;
        
        for(int i = 1 ; i < n ; i++){
            int diff = timeSeries[i]-timeSeries[i-1];
            if(diff >= duration) cnt += duration;
            else cnt += diff;
        }
        if(n != 0)
        cnt += duration;
        return cnt;
    }
};

