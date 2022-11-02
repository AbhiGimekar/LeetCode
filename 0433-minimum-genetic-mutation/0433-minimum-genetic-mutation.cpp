class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        
        unordered_set<string> st;
        for(auto  i:bank)
            st.insert(i);
        queue<pair<string,int>> q;
        q.push({start, 0});
        
        while(!q.empty()){
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();
            
            if(word == end) return steps;
            
            for(int i=0; i<8; i++)
            {
                char original = word[i];
                for(char ch='A'; ch<='T'; ch++){
                    word[i] = ch;
                    if(st.find(word) != st.end()){
                        st.erase(word);
                        q.push({word, steps+1});
                    }
                }
                word[i] = original;
            }
        }
        return -1;
    }
};