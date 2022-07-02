class Solution {
public:
    int maxArea(int h, int w, vector<int>& hori, vector<int>& verti) {
        
        long long mod = 1e9 + 7;
        
        hori.push_back(0);
        verti.push_back(0);
        hori.push_back(h);
        verti.push_back(w);
        
        sort(begin(hori) , end(hori));
        sort(begin(verti), end(verti));
        
        int maxHeight = -1;
        
        for(int i=0 ; i<hori.size()-1 ; i++)
        {
            maxHeight = max(maxHeight , hori[i+1]-hori[i]);
        }
        
        int maxWidth = -1;
        
        for(int i=0 ; i<verti.size()-1 ; i++)
        {
            maxWidth = max(maxWidth , verti[i+1]-verti[i]);
        }
        
        return ((maxHeight%mod)*(maxWidth%mod))%mod;
        
        
    }
};