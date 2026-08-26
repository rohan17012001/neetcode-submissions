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
    // bool check(TreeNode* root, TreeNode* subRoot){
    //     if(!root && !subRoot) return true;
    //     if(!root || !subRoot) return false;
    //     if(root->val != subRoot->val) return false;
    //     return check(root->left, subRoot->left) && check(root->right , subRoot->right);
    // }
    void serialize(TreeNode* node, string& s){
        if(node==NULL){
            s+=",#";
            return;
        }
        s+=","+to_string(node->val);
        serialize(node->left, s);
        serialize(node->right, s);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // if(!root && !subRoot) return true;
        // if(!root || !subRoot) return false;
        // bool f1=isSubtree(root->left, subRoot->left);
        // bool f2 = f1 && (root->val == subRoot->val);
        // bool f3 = f2 || isSubtree(root->right, subRoot->right);
        // return f3;
        string s="", t="";
        serialize(root, s);
        serialize(subRoot, t);
        return s.find(t)!=string::npos;
    }
};
