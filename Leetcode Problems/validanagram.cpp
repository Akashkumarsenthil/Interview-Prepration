class Solution {
public:
    bool isAnagram(string s, string t) {
        
        map<char,int> mp;
        for(auto c:s){
            mp[c]++;
        }
        for(auto c:t){
            mp[c]--;
        }
        
        for(auto num:mp){
            if(num.second!=0){
                return false;
            }
        }
        return true;
        
    }
};