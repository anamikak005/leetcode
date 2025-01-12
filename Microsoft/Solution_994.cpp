/*
Runtime: 0 ms
Beats: 100.00%
*/

class Solution {
    bool isValidCell (int i, int j, int n, int m) {
        return (i > -1 && j > -1 && i < n && j < m);
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> rottenOranges;
        vector<pair<int,int>> adjacentCell = {{-1, 0}, {1,0}, {0,-1}, {0,+1}};
        int freshOranges = 0, rottedOranges = 0, size = 0, maxMinute = -1;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == 2) {
                    rottenOranges.push({i,j});
                } else if (grid[i][j] == 1) {
                    freshOranges++;
                }
            }
        }

        while(!rottenOranges.empty()) {
            maxMinute++;
            size = rottenOranges.size();
            while(size--) {
                pair<int,int> cell = rottenOranges.front();
                rottenOranges.pop();
                for (int i = 0; i < 4; i++) {
                    int adjacentI = cell.first + adjacentCell[i].first;
                    int adjacentJ = cell.second + adjacentCell[i].second;
                    if(isValidCell(adjacentI, adjacentJ, grid.size(), grid[0].size()) && grid[adjacentI][adjacentJ] == 1) {
                        grid[adjacentI][adjacentJ] = 2;
                        rottenOranges.push({adjacentI, adjacentJ});
                        rottedOranges++;
                    }
                }
            }
        }
        if(maxMinute == -1) maxMinute = 0;
        return rottedOranges == freshOranges? maxMinute : -1;

    }
};