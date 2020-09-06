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
    void inorder(TreeNode* r, vector<int> &v){
        if(r == NULL) return;
        inorder(r->left,v);
        v.push_back(r->val);
        inorder(r->right,v);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> res1;
        vector<int> res2;
        vector<int> res;
        inorder(root1,res1);
        inorder(root2,res2);
        int p1  = 0 ,p2 = 0;
        while(p1 < res1.size() && p2 < res2.size()){
            if(res1[p1] < res2[p2]){
                res.push_back(res1[p1]);
                p1++;
            }
            else{
                res.push_back(res2[p2]);
                p2++;
            }
        }
        while(p1 < res1.size()){
            res.push_back(res1[p1]);
            p1++;
        }
        while(p2 < res2.size()){
            res.push_back(res2[p2]);
            p2++;
        }
        return res;
    }
};
