/*
Runtime: 0 ms
Beats: 100.00%
*/

class Solution {
public:
    bool checkString(string s) {
        int i = 0;
        bool hasEncounterB = false;
        while(i < s.size()) {
            if(s[i] == 'a' && hasEncounterB)
                return false;
            else if(s[i] == 'b' && !hasEncounterB)
                hasEncounterB = true;
            i++;
        }
        return true;
    }
};