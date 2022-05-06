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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            int size = q.size();
            
            vector<int> curLevel;
            for(int i=0 ; i<size ; i++){
                TreeNode* temp = q.front() ; q.pop();
                if(temp != NULL){
                    curLevel.push_back(temp->val);
                    q.push(temp->left);
                    q.push(temp->right);
                }
            }
            
            if(curLevel.size() > 0){
                ans.push_back(curLevel);
            }
        }
        
        return ans;
    }
};