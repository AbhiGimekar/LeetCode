class Solution {
public:
    int divisorSubstrings(int num, int k) {
        
        string str = to_string(num); //converting the num in the string first using the inbuilt function
        int n = str.size();
        int ans = 0;
        for(int i = 0;i<=(n-k);i++)
		{
            if(stoi(str.substr(i,k)) != 0) // converting string into integer
				if(num % stoi(str.substr(i,k)) == 0 ) //when remainder is 0 increament the counter
					ans++;
        }
        return ans;
        
    }
};