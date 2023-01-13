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
    int cnt = 0;
    pair<int,int> rec(TreeNode* root){
        if(root==NULL) return {0,0};
        auto a = rec(root->left);
        auto b = rec(root->right);
        int x = 1+a.first+b.first;
        int y = root->val + a.second+b.second;
        if(y/x == root->val){
            cnt++;
        }
        return {x,y};
    }

    int averageOfSubtree(TreeNode* root) {
       cnt = 0;
       rec(root); 
       return cnt;
    }
};
