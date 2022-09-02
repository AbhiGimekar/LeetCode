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
    vector<double> averageOfLevels(TreeNode* root) {
        
        vector<double> ans;
        if(root == NULL) return ans;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            int n = q.size();
            vector<double> level;
            for(double i=0 ; i<n; i++){
                TreeNode *node = q.front();  q.pop();
                
                if(node->left != NULL) q.push(node->left);
                if(node->right != NULL) q.push(node->right);
                level.push_back(node->val);
            }
            
            double sum = 0 ,cnt=0;
            for(auto i:level){
                sum+=i;cnt++;
            }
            
            ans.push_back(sum/cnt);
        }
        
        return ans;
        
        
    }
};