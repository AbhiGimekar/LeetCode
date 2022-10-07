class MyCalendarThree {
    map<int,int> mp;
public:
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        
        mp[start]++;
        mp[end]--;
        
        int cur = 0 , maxi = 0;
        for(auto  i:mp)
        {
            cur += i.second;
            maxi = max(maxi , cur);
        }
        
        return maxi;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */