class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        int i = 0;
        vector<vector<int>> res;
        while( i < n && newInterval[0] > intervals[i][1] )  res.push_back(intervals[i++]);
        vector<int> tmp = newInterval;                                                          
        while( i < n && newInterval[1] >= intervals[i][0]){
            tmp[0] = min(tmp[0],intervals[i][0]);
            tmp[1] = max(tmp[1],intervals[i++][1]);
        }
        res.push_back(tmp);
    
        while(i < n){
           res.push_back(intervals[i++]);
        }
        return res;
    }
};

