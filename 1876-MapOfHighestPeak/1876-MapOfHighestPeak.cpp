// Last updated: 11/25/2026, 3:43:09 PM
class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        vector<pair<int,int>>arr;

        for(int row = 0;row < isWater.size();row++){
            for(int column = 0;column < isWater[0].size();column++){
                if(isWater[row][column] == 1){
                    arr.push_back({row,column});
                    isWater[row][column] = 0;
                }else{
                    isWater[row][column] = -1;
                }
            }
        }   

        while(!arr.empty()){
            vector<pair<int,int>>temp;
            for(auto [row,col] : arr){
                if(row - 1 >= 0 && isWater[row-1][col] == -1){
                    isWater[row - 1][col] = isWater[row][col] + 1;
                    temp.push_back({row - 1,col});
                }
                if(col + 1 < isWater[0].size() && isWater[row][col + 1] == -1){
                    isWater[row][col + 1] = isWater[row][col] + 1;
                    temp.push_back({row , col + 1});
                }
                if (row + 1 < isWater.size() && isWater[row + 1][col] == -1) {
                    isWater[row + 1][col] = isWater[row][col] + 1;
                    temp.push_back({row + 1, col});
                }
                if (col - 1 >= 0 && isWater[row][col - 1] == -1) {
                    isWater[row][col - 1] = isWater[row][col] + 1;
                    temp.push_back({row, col - 1});
                }
            }
            arr = temp;
        }

        return isWater;

    }

};