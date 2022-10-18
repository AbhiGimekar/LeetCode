class Solution {
public:
    string countAndSay(int n) {
        
        string curr_str;
        curr_str += '1';
        
        for (int i = 0; i < n - 1; i++)
        {
            string buffer;

            int index = 0;
            for (int index = 0; index < curr_str.size(); ++index)
            {
                int cnt = 1; 

                while (index + 1 < curr_str.size() and curr_str[index + 1] == curr_str[index]) 
                {
                    index++;
                    cnt++;
                }

                buffer.push_back(cnt + '0');
                buffer.push_back(curr_str[index]);
            }

            curr_str = buffer;
        }
        
        return curr_str;
    }
};