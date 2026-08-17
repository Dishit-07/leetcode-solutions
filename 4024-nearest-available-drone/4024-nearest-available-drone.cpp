class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int ans = -1;
        int n = drones.size();
        int minDist = INT_MAX;
        
        for(int i = 0; i<n;i++){
            int dist = abs(drones[i][0] - target[0]) + abs(drones[i][1]- target[1]);
            int range = drones[i][2];
            if(dist<= range){
                if(dist < minDist){
                minDist = dist;
                ans = i;
                }
            }
            
        }
        return ans;
    }
};