// Last updated: 11/25/2026, 3:46:00 PM
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int fleetCount = 1;
        int n = position.size();
        vector<pair<double,double>> cars(n);

        for(int i = 0 ;i < n ;i++){
            cars[i].first = position[i];
            cars[i].second = (target - position[i]) / (double)speed[i];
        }
        sort(cars.begin(), cars.end());

        double timeTaken = cars[n-1].second;

        for(int i = n-2 ; i>=0 ;i--){
            if(timeTaken < cars[i].second){
                fleetCount++;
                timeTaken = cars[i].second;
            }
        }
        return fleetCount;
    }
};