class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> mp1(26, 0), mp2(26, 0);
    int k = s1.size(), n = s2.size();

    if(k > n) return false;

    for(char ch : s1) mp1[ch - 'a']++;

    int matchCount = 0;
    for(int i = 0; i < k; i++) {
        mp2[s2[i] - 'a']++;
    }
    for(int i = 0; i < 26; i++) {
        if(mp1[i] == mp2[i]) matchCount++;
    }

    for(int i = k; i < n; i++) {
        if(matchCount == 26) return true;

        int in = s2[i] - 'a';       // new character entering the window
        int out = s2[i - k] - 'a';  // character leaving the window

        mp2[in]++;
        if(mp2[in] == mp1[in]) matchCount++;
        else if(mp2[in] - 1 == mp1[in]) matchCount--;

        mp2[out]--;
        if(mp2[out] == mp1[out]) matchCount++;
        else if(mp2[out] + 1 == mp1[out]) matchCount--;
    }

    return matchCount == 26;
    }
};