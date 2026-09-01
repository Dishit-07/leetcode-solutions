#include <vector>
#include <string>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minMoves(vector<string>& grid, int energy) {
        int m = grid.size();
        int n = grid[0].size();
        
        int startR = -1, startC = -1;
        vector<pair<int, int>> litters;
        
        // Step 1: Parse grid for Start position & Litters mapping
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == 'S') {
                    startR = r;
                    startC = c;
                } else if (grid[r][c] == 'L') {
                    litters.push_back({r, c});
                }
            }
        }
        
        int numLitters = litters.size();
        int targetMask = (1 << numLitters) - 1;
        
        if (numLitters == 0) return 0;
        
        vector<vector<int>> litterIdx(m, vector<int>(n, -1));
        for (int i = 0; i < numLitters; i++) {
            litterIdx[litters[i].first][litters[i].second] = i;
        }
        
        vector<vector<vector<int>>> maxEnergyLeft(
            m, vector<vector<int>>(n, vector<int>(1 << numLitters, -1))
        );
        
        queue<tuple<int, int, int, int>> q;
        
        q.push({startR, startC, 0, energy});
        maxEnergyLeft[startR][startC][0] = energy;
        
        int moves = 0;
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto [r, c, mask, e] = q.front();
                q.pop();
                
                if (mask == targetMask) return moves;
                
                if (e == 0 && grid[r][c] != 'R') continue;
                
                for (int i = 0; i < 4; i++) {
                    int nr = r + dr[i];
                    int nc = c + dc[i];
                    
                    if (nr < 0 || nr >= m || nc < 0 || nc >= n || grid[nr][nc] == 'X') {
                        continue;
                    }
                    
                    int nextE = e - 1;
                    if (nextE < 0) continue;
                    
                    int nextMask = mask;
                    char nextCell = grid[nr][nc];
                    
                    if (nextCell == 'R') {
                        nextE = energy;
                    } else if (nextCell == 'L') {
                        int idx = litterIdx[nr][nc];
                        if (!(mask & (1 << idx))) {
                            nextMask |= (1 << idx);
                        }
                    }
                    
                    if (nextE > maxEnergyLeft[nr][nc][nextMask]) {
                        maxEnergyLeft[nr][nc][nextMask] = nextE;
                        q.push({nr, nc, nextMask, nextE});
                    }
                }
            }
            moves++;
        }
        
        return -1;
    }
};