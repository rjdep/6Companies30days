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
    
    map<TreeNode*,int> copy;
    int dp[10010][2];

    int rec(TreeNode* root, int prev){
        if(root==NULL) return 0;
        if(dp[copy[root]][prev] != -1) return dp[copy[root]][prev];
        int ans = 0;
        if(prev){
            ans += (rec(root->left,0)+rec(root->right,0));
        }else{
            ans += max(rec(root->left,0)+rec(root->right,0),rec(root->left,1)+rec(root->right,1)+root->val);
        }
        return dp[copy[root]][prev]=ans;
    }
    
    int rob(TreeNode* root) {
        copy.clear();
        queue<TreeNode*>q;
        q.push(root);
        int cnt = 0;
        while(!q.empty()){
            int n = q.size();
            while(n--){
                auto it = q.front();
                q.pop();
                copy[it]=cnt++;
                if(it->left){
                    q.push(it->left);
                }
                if(it->right){
                    q.push(it->right);
                }
            }
        }
        for(int i=0; i<=cnt+5; i++){
            dp[i][0]=-1;
            dp[i][1]=-1;
        }
        return rec(root,0);
    }
};
