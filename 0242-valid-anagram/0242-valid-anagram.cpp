class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char,int>mp;
        // map<char,int>mp2;
        if(s.size() != t.size())return false;
        for(int i = 0 ; i< s.size() ; i++){
            mp[s[i]]++;
        }
        for(int i = 0 ; i< t.size() ; i++){
            if(mp.find(t[i]) != mp.end()){mp[t[i]]--;}
            else{
                return false;
            }
        }
        
        return true;
        
    }
};