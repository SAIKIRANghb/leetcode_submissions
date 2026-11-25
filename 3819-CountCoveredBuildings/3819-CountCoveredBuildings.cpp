// Last updated: 11/25/2026, 3:37:47 PM
class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        int coveredBuildings = 0;
        int bn = buildings.size();
        unordered_map<int, pair<int, int>> mpX;
        unordered_map<int, pair<int, int>> mpY;
        
        sort(buildings.begin(),buildings.end());

        for(int i = 0; i < bn; i++) {
            int x_cord = buildings[i][0];
            int y_cord = buildings[i][1];
            
            if (mpX.find(x_cord) == mpX.end()) {
                mpX[x_cord] = {y_cord, INT_MIN};  // first occurring y at x_cord
            } else {
                auto fir_lst = mpX[x_cord];
                mpX[x_cord] = {fir_lst.first,y_cord};// last occurring y at x_cord
            }

            if (mpY.find(y_cord) == mpY.end()) {
                mpY[y_cord] = {x_cord, INT_MIN};  // first occurring x at y_cord
            } else {
                auto fir_lst = mpY[y_cord];
                mpY[y_cord] = {fir_lst.first,x_cord};// last occurring x at y_cord
            }
        }
        
        for (int i = 0; i < bn; i++) {
            int x = buildings[i][0];
            int y = buildings[i][1];
            int firstXinY = mpX[x].first;
            int lastXinY = mpX[x].second;
            
            int firstYinX = mpY[y].first;
            int lastYinX = mpY[y].second;
            
            if (y > firstXinY && y < lastXinY && x > firstYinX && x < lastYinX) {
                coveredBuildings++;
            }
        }
        
        return coveredBuildings;
    }
};
