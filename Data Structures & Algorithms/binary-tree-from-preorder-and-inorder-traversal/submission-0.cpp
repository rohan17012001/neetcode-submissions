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
    TreeNode* solve(vector<int>& preorder, int pstart, int pend, vector<int>& inorder, int istart, int iend){
        if(pstart>pend || istart>iend) return nullptr;
        cout<<"pstart: "<<pstart<<" pend: "<<pend<<"\n";
        TreeNode* node=new TreeNode(preorder[pstart]);
        int ind;
        for(int i =istart; i<=iend; i++){
            if(inorder[i]==preorder[pstart]){
                ind=i;
                break;
            }
        }
        int interval=ind-istart;
        node->left=solve(preorder, pstart+1, pstart+interval, inorder, istart, ind-1);
        node->right=solve(preorder, pstart+interval+1, pend, inorder, ind+1, iend);
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        TreeNode* ans= solve(preorder, 0, n-1, inorder, 0, n-1);
        return ans;
    }
};
