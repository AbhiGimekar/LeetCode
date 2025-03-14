class ATM {
    long long bank[5] = {} , val[5] = {20, 50, 100, 200, 500};
public:
    ATM() {
        
    }
    
    void deposit(vector<int> banknotesCount) {
        
        for(int i=0 ; i<banknotesCount.size() ; i++){
            bank[i] += banknotesCount[i];
        }
    }
    
    vector<int> withdraw(int amount) {
        vector<int> take(5);
        for (int i = 4; i >= 0; --i) {
            take[i] = min(bank[i], amount / val[i]);
            amount -= take[i] * val[i];
        }
        if (amount)
            return { -1 };
        for (int i = 0; i < 5; ++i)
            bank[i] -= take[i];            
        return take;
    }
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */