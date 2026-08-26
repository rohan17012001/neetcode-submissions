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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans;
        queue<TreeNode*> q;
        if(root) q.push(root);
        while(!q.empty()){
            TreeNode* temp=q.front();
            q.pop();
            if(!temp) ans.append("#,");
            else{
                ans.append(to_string(temp->val)+",");
                q.push(temp->left);
                q.push(temp->right);
            }
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()) return nullptr;
        stringstream s(data);
        string str;
        getline(s, str, ',');
        TreeNode* ans=new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(ans);
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            getline(s, str, ',');
            if(str=="#"){
                node->left=nullptr;
            }
            else{
                TreeNode* temp=new TreeNode(stoi(str));
                node->left=temp;
                q.push(temp);
            }
            getline(s,str, ',');
            if(str=="#"){
                node->right=nullptr;
            }
            else{
                TreeNode* temp=new TreeNode(stoi(str));
                node->right=temp;
                q.push(temp);
            }
        }
        return ans;
    }
};
