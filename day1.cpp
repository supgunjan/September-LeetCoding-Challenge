class Solution {
public:
    bool validTime(vector<int> &t){
        if(t[0] > 2) return false;
        else{
            if(t[0] == 2 && t[1] > 3) return false;
            if(t[2] > 5) return false;
        }
        return true;
    }
    
    string largestTimeFromDigits(vector<int>& A) {
        vector<vector<int>> tmp;
        if(A[0] == 0 && A[1] == 0 && A[2] == 0 && A[3] == 0 ) return "00:00"; 
        sort(A.begin(),A.end());
        if(validTime(A)){
            tmp.push_back(A);
        }
        while( next_permutation(A.begin(), A.end())){
            if(validTime(A)){
                tmp.push_back(A);
            }
        }
        string res;
        if(tmp.size() != 0){
            int n = tmp.size()-1;
            res += to_string(tmp[n][0]);
            res += to_string(tmp[n][1]);
            res += ':';
            res += to_string(tmp[n][2]);
            res += to_string(tmp[n][3]);
        }
        return res;
    }
};

