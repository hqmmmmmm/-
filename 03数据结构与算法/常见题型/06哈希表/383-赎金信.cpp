class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> h1, h2;
        for(char c : ransomNote) 
            h1[c]++;
        for(char c : magazine)
            h2[c]++;

        for(auto &[k, v] : h1) {
            if(v > h2[k]) 
                return false;
        }

        return true;
    }
};