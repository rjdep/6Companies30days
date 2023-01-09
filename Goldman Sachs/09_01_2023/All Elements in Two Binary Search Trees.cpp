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

    vector<int> MORRIS_TRAVERSAL(TreeNode* root){
        TreeNode* root1 = root;
        vector<int> ans;
        while(root1){
            if(root1->left==NULL){
                ans.push_back(root1->val);
                root1 = root1->right;
            }else{
                TreeNode* prev = root1->left;
                while(prev->right && prev->right != root1){
                    prev = prev->right;
                }
                if(prev->right==NULL){
                    prev->right = root1;
                    root1 = root1->left;
                }else{
                    prev->right = NULL;
                    ans.push_back(root1->val);
                    root1=root1->right;
                }
            }
        }
        return ans;
    }

    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> a,b,ans;
        a = MORRIS_TRAVERSAL(root1);
        b = MORRIS_TRAVERSAL(root2);
        int n = a.size(), m = b.size();
        int i = 0, j = 0;
        while(i<n && j<m){
            if(a[i]<=b[j]){
                ans.push_back(a[i]);
                i++;
            }else{
                ans.push_back(b[j]);
                j++;
            }
        }
        while(i<n){
            ans.push_back(a[i]);
            i++;
        }
        while(j<m){
            ans.push_back(b[j]);
            j++;
        }
        return ans;
    }
};
