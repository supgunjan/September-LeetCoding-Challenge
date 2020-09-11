class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i = 0 ;
        int j = 0 ;
        int n1 = version1.length();
        int n2 = version2.length();
       
        while( i < n1 && j < n2 ){
            
            string tmp1;
            while(i < n1 && version1[i] != '.'){
                tmp1 += version1[i];
                i++;
            }
            string tmp2;
            while(j < n2 && version2[j] != '.' ){
                tmp2 += version2[j];
                j++;
            }
            int res1 = 0;
            int res2 = 0;
            int k1 = 0;
            int k2 = 0;
            while( k1 < tmp1.length()){ res1 = res1*10 + (tmp1[k1]-'0');    k1++;}
            while( k2 < tmp2.length()){ res2 = res2*10 + (tmp2[k2]-'0');    k2++;}
            if(res1 > res2) return 1;
            else if(res1 < res2) return -1;
            i++;
            j++;
        }
        while( i < n1){
            if(version1[i] != '.' && version1[i] > '0') return 1;
            i++;
        }
        while( j < n2){
            if(version2[j] != '.' && version2[j] > '0') return -1;
            j++;
        }
        return 0;
    }
};
