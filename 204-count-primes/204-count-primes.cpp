class Solution {
public:
    
    
    int SeiveOfEratosthens(int n)
    {   
        vector<bool> prime(n+1 , true);
        for(int i=2 ; i*i <= n ; i++)
        {
            if(prime[i] == true){
                for(int j = i*i ; j<=n ; j+=i)
                    prime[j] = false;
            }
        }
        
        int cnt = 0;
        for(int i=2 ; i<n ; i++){
            if(prime[i] == true)
                cnt++;
        }
        
        return cnt;
    }
    
    int countPrimes(int n) {
        
        
        return SeiveOfEratosthens(n);
        
        
    }
};