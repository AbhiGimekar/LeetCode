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
        if(root==NULL )
            return 0;
        
        vector<vector<int>> ans;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            int size = q.size();
            vector<int>level;
            
            for(int i=0 ; i<size ; i++){
                auto node = q.front();
                q.pop();
                if(node->left != NULL)
                    q.push(node->left);
                if(node->right!=NULL)
                    q.push(node->right);
                level.push_back(node->val);
            }
            ans.push_back(level);
        }
        
        // for(auto i:ans){
        //     for(auto v:i)
        //         cout<<v<<" ";
        //     cout<<endl;
        // }
        int x = ans.size();
        int y = ans[x-1].size();
        
        int sum=0;
        for(int i=0 ;i<y ; i++)
            sum+=ans[x-1][i];
        
        return sum;
        
    }
};