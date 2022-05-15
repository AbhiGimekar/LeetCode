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
    int deepestLeavesSum(TreeNode* root) {
        
        queue<TreeNode*> fillValues;
        fillValues.push(root);
        
        int deepestLeafSum = 0;
        while(!fillValues.empty()){
            int size = fillValues.size(), sum = 0;
            
            for(int i = 0; i < size; i++){
                TreeNode *node = fillValues.front();
                fillValues.pop();
                
                sum += node->val;
                if(node->left  != nullptr) 
                    fillValues.push(node->left);
                
                if(node->right != nullptr) 
                    fillValues.push(node->right);
            }
            
            deepestLeafSum = sum;
        }
        
        return deepestLeafSum;
    }
};