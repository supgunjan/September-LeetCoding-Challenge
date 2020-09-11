/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int sm ;
    void helper(TreeNode* root,int i,vector<int> &v){
       
        
        v[i] = root->val;
        if(root->left == NULL && root->right == NULL)
        {
            bitset<32> bitarray;
            for(int j = 0 ; j <= i ; j++){
                bitarray[i-j] = v[j];
            }
            //cout<<bitarray.to_ulong()<<endl;
            sm += bitarray.to_ulong();
        }
        if(root->left)   helper(root->left,i+1,v);
        if(root->right)   helper(root->right,i+1,v);
    
    }
    int sumRootToLeaf(TreeNode* root) {
         vector<int> v(32,0);
         helper(root,0,v);
        return sm;
    }
};
