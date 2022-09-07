class Solution {
public:
    bool isIsomorphic(string s, string t) 
    {
        int map[128];
        bool isIso = true;
        
        for (int i = 0; i < s.size() && isIso; i++) 
            map[s[i]] = -1;
        
        for (int i = 0; i < s.size(); i++) 
        {
            if (map[s[i]] == -1)
                map[s[i]] = t[i];
            else if (map[s[i]] != t[i]) 
                isIso = false;
        }
        
        for (int i = 0; i < t.size() && isIso; i++) 
            map[t[i]] = -1;
        
        for (int i = 0; i < t.size(); i++) 
        {
            if (map[t[i]] == -1)
                map[t[i]] = s[i];
            else if (map[t[i]] != s[i]) 
                isIso = false;
        }
        
        return isIso;
    }
};