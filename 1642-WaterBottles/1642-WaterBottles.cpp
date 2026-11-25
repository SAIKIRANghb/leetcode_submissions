// Last updated: 11/25/2026, 3:43:40 PM
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        // if(numBottles < numExchange)return numBottles;
        // int count = 0;
        // int full = numBottles , empty = 0;
        // do{
        //     count += full;
        //     empty = empty + full; 
        //     full = empty / numExchange;
        //     empty = empty % numExchange; 
        // }while((empty + full) >= numExchange);
        // cout<< full;
        // return count + full;
        return numBottles + ((numBottles-1) / (numExchange - 1));
    }
};