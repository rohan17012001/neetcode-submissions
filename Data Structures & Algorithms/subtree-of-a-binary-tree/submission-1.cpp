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
    // void serialize(TreeNode* node, string& s){
    //     if(node==NULL){
    //         s+=",#";
    //         return;
    //     }
    //     s+=","+to_string(node->val);
    //     serialize(node->left, s);
    //     serialize(node->right, s);
    // }

    bool isSame(TreeNode* root, TreeNode* subRoot){
        if(!root && !subRoot) return true;
        if(root && subRoot && root->val == subRoot->val){
            return isSame(root->left, subRoot->left) && isSame(root->right, subRoot->right);
        }
        return false;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // string s="", t="";
        // serialize(root, s);
        // serialize(subRoot, t);
        // return s.find(t)!=string::npos;
        
        if(!subRoot) return true;
        if(!root) return false;
        if(isSame(root, subRoot)) return true;
        return isSubtree(root->left, subRoot)||isSubtree(root->right, subRoot);
    }
};
