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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    
        //if(inorder.size() != postorder.size()) return NULL;
        map<int , int> index;
        
        for(int i=0 ; i<inorder.size() ; i++)
            index[inorder[i]] = i;
        
        return buildTree(inorder , 0 , inorder.size()-1 , 
                        postorder , 0 , postorder.size()-1 , index);
        
    }
    
    TreeNode* buildTree(vector<int> &inorder , int inStart , int inEnd , 
                       vector<int> &postorder , int postStart , int postEnd, 
                       map<int , int> &index)
    {
        if(postStart > postEnd || inStart > inEnd) return NULL;
        
        TreeNode* root = new TreeNode(postorder[postEnd]);
        int root_ind = index[postorder[postEnd]];
        
        root->left = buildTree(inorder , inStart , root_ind - 1 ,
                              postorder , postStart , postStart + root_ind - inStart - 1 ,
                              index);
        
        root->right = buildTree(inorder , root_ind + 1 , inEnd , 
                               postorder , postStart + root_ind - inStart , postEnd-1 , 
                               index);
        
        return root;
    }
};