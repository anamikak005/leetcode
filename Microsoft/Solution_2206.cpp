/**
// Runtime
// 0 ms Beats 100.00%
*/

class Solution {
public:
    bool divideArray(vector<int>& nums) {
        vector<int> map(501, 0);
        for(int i = 0;i < nums.size(); i++) {
            map[nums[i]]++;
        }
        for(int i = 0; i < map.size(); i++) {
            if(map[i] % 2 != 0)
                return false;
        }
        return true;
    }
};