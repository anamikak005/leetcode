/*
Runtime: 141ms
Beats: 67.76%
*/

class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        sort(changed.begin(), changed.end());
        unordered_map<int, int> umap;
        vector<int> answer;
        for(int i = 0; i < changed.size(); i++) {
            umap[changed[i]]++;
        }
        //only 0 is a digit where 2*0 = 0/2 = 0
        if(umap[0]%2 != 0) return {};
        for (int i = 0; i < changed.size(); i++) {
            if(umap[changed[i]] == 0) continue; //changed[i]*2 for some changed[i]
            //either half or double should be present
            if(umap[changed[i]/2] == 0 && umap[changed[i] * 2] == 0)
                return {};
            if(umap[changed[i]*2] != 0 && umap[changed[i]] > 0) {
                //remove the twice and current value
                umap[changed[i]*2] --;
                umap[changed[i]] --;
                answer.push_back(changed[i]);
            }
        }
        return answer;
    }
};