// Last updated: 11/25/2026, 3:43:17 PM
class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n = customers.size();
        int time = 0;
        double Avg = 0;
        for(int i = 0;i<n;i++){
            int arrived = customers[i][0];
            int duration = customers[i][1];
            int inBtw = arrived - time;
            if(inBtw < 0){
                inBtw = 0;
            }
            time += duration + inBtw;
            int waiting = time - arrived;
            Avg += (waiting/(double)n);
        }
        return Avg; 
    }
};