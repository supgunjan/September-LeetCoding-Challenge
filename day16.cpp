struct Node{
    Node* zero;
    Node* one;
    bool end;   
};
Node* newNode(){
    Node* tmp = new Node();
    tmp->one = NULL;
    tmp->zero = NULL;
    tmp->end = false;
    return tmp;
}
void insert(Node* root, int num){
    Node *tmp = root;
    for(int i = 31; i >= 0; i--){
        if((1 << i) & num){
            // 1 is set
            if(tmp->one == NULL){
                tmp->one = newNode();
            }
            tmp = tmp->one;
        }else{
            // 0 is set
            if(tmp->zero == NULL){
                tmp->zero = newNode();                
            }
            tmp = tmp->zero;
        }        
    }        
    tmp->end = true;
}
 
int maxAns(Node* root, int num){
 
    int ans[32] = {0};
    Node* tmp = root;
 
    for(int i = 31; i >= 0; i--){
        int one_or_zero = (1 << i) & num;
        if(one_or_zero > 0){
            // 1 & 1
            if(tmp->zero){
                tmp = tmp->zero;
                ans[i] = 1;
            }else if(tmp->one){
                tmp = tmp->one;   
            }
        }else{
            //1 & 0
            if(tmp->one){
                tmp = tmp->one;
                ans[i] = 1;
            }else if(tmp->zero){
                tmp = tmp->zero;
            }
        }
    }
    int res = 0;
    for(int i = 0; i < 32; i++){
        if(ans[i]){
            res += (1 << i);
        }
    }
    return res;
}
 
class Solution {
 
public:
    int findMaximumXOR(vector<int>& nums) {
        Node* root = newNode();
        for(int i = 0; i < nums.size(); i++){
            insert(root, nums[i]);
        }
        int ans = 0;
        for(int i = 0; i < nums.size(); i++){
            ans = max(ans, maxAns(root, nums[i]));
        }
        return ans;
    }
};
