class Solution {
public:
    bool checkIfPangram(string sentence) {
        
        int num = 0;
        
        for(auto i:sentence)
        {
            int index = i - 'a';
            int curBit = 1 << index;
            
            num |= curBit;
        }
        
        return num ==(1<<26)-1;
    }
};