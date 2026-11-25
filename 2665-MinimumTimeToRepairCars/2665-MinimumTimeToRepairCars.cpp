// Last updated: 11/25/2026, 3:41:02 PM
class Solution {
public:
    bool canAchieveMidTime(vector<int>&ranks,int cars,long long TimeToRepair){
        long long carsRepairs = 0;
        for(int i = 0;i < ranks.size();i++){
            carsRepairs += (long long)sqrt(TimeToRepair / ranks[i] * 1LL);
            if(carsRepairs >= cars)return true;
        }
        return false;
    }

    long long repairCars(vector<int>& ranks, int cars) {
        long long maxTime = LLONG_MAX;
        long long l = 0 , r = maxTime;
        while(l <= r){
            long long mid = l + (r - l) / 2;
            if(canAchieveMidTime(ranks,cars,mid)){
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }
        return l;
    }
};