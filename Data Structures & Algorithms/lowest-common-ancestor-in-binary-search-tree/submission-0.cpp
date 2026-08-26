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
    // void fillmap(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& m){
    //     if(!root) return;
    //     if(root->left) m[root->left]=root;
    //     if(root->right) m[root->right]=root;
    //     fillmap(root->left, m);
    //     fillmap(root->right, m);
    // }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // unordered_map<TreeNode*, TreeNode*> m;
        // m[root]=nullptr;
        // fillmap(root, m);
        // TreeNode* ans=nullptr;
        // while(p && q){
        //     if(p==q) ans=p;
        //     p=m[p];
        //     q=m[q];
        // }
        // return ans;
        if(!root) return nullptr;
        if(root==p || root==q) return root;
        TreeNode* lnode=lowestCommonAncestor(root->left, p, q);
        TreeNode* rnode=lowestCommonAncestor(root->right, p, q);
        if(lnode && rnode) return root;
        return lnode?lnode:rnode;
    }
};
