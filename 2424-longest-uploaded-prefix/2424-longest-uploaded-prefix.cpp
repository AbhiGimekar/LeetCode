class LUPrefix {
    set<int>s;
    int last=0;
public:
    LUPrefix(int n) {
        
    }
    
    void upload(int video) {
        s.insert(video);
        while(s.count(last+1))last++;
    }
    
    int longest() {
        return last;
    }
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */