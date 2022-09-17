class Solution {
struct TrieNode{
        TrieNode* child[26];
        int index;
        TrieNode(){
            for(int i =  0;i<26;i++)
                child[i] = NULL;
            index = -1;
        }
    };
    
    TrieNode *root;
    
    void insert(string &w,int &idx){
        TrieNode *p = root;
        for(auto ch:w){
            if(!p->child[ch-'a'])
                p->child[ch-'a'] = new TrieNode();
            p = p->child[ch-'a'];
        }
        p->index = idx;
    }
    
    bool search(string &w,int strt,int end,int &i){
        TrieNode *p = root;
        for(;end>=strt;end--){
            char ch = w[end];
            if(!p->child[ch-'a'])
                return false;
            p = p->child[ch-'a'];
        }
        i = p->index;
        return p->index!=-1;
    }
    
    bool ispalin(string &w,int i,int j)
    {
        while(i<j)
            if(w[i++]!=w[j--])
                return false;
        return true;
    }    
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        root = new TrieNode();
        for(int i = 0;i<words.size();i++)
            insert(words[i],i);
        
        vector<vector<int>>ans;
        
        if(root->index!=-1)
            for(int j = 0;j<words.size();j++)
                if(j!=root->index && ispalin(words[j],0,words[j].length()-1)){
                    ans.push_back({root->index,j});
                    ans.push_back({j,root->index});
                }
        
         for(int i = 0; i < words.size(); i++)
             for(int j = 1; j <= words[i].length(); j++) {
                 int leftright = j-1;
                 int rightright = words[i].length()-1;
                 int temp;
                 
                 if(search(words[i],0,leftright,temp) && ispalin(words[i],j,rightright) && temp != i) 
                     ans.push_back({i, temp});
                 
                 if(j==words[i].length())continue;
                 if(search(words[i],j,rightright,temp) && ispalin(words[i],0,leftright) && temp != i) 
                     ans.push_back({temp, i});
                 
             }
         
         return ans;        
     }
};