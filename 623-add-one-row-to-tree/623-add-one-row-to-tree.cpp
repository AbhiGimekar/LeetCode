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
    
    void insert(TreeNode* root , int val , int depth , int n)
    {
        if(!root)return ;
        if(depth == n-1)
        {
            TreeNode* newNode = root->left;
            root->left = new TreeNode(val);
            root->left->left = newNode;
            newNode = root->right;
            root->right = new TreeNode(val);
            root->right->right = newNode;
        }
        else{
            insert(root->left , val , depth+1 , n);
            insert(root->right , val , depth+1 , n);
        }
    }
    
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        
        if(depth == 1){
            TreeNode* newNode = new TreeNode(val);
            newNode->left = root;
            return newNode;
        }
        
        insert(root , val , 1 , depth);
        return root;
    }
};