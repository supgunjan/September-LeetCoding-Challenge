const int dx[] = {0, -1, 0, 1};
const int dy[] = {1, 0, -1, 0};
class Solution {
public:
    bool isRobotBounded(string instructions) {
       int dir = 0; // N
       pair<int, int> st = {0, 0};
       for(auto &c : instructions){
           if(c == 'R'){
               dir = (dir + 3) % 4;
           }else if(c == 'L'){
               dir = (dir + 1) % 4;
           }else{               
               st = {st.first + dx[dir], st.second + dy[dir]};
           }
       } 
       return st == make_pair(0, 0) || dir != 0;
    }
};

