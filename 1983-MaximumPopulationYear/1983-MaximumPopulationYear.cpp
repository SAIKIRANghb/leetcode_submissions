// Last updated: 11/25/2026, 3:42:49 PM
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        unordered_map<int, int> population;
        int arr[101]={0};
        for(vector<int> it :logs){
            arr[it[0]-1950]++;
            arr[it[1]-1950]--;
        }
        for(int i=1;i<101;i++){
            arr[i]=arr[i]+arr[i-1];
        }
        int maxi;
        int maxyr=1;
        for(int i=0;i<101;i++){
            if(arr[i]>maxi || arr[i]==maxi && i<maxyr){
                maxi=arr[i];
                maxyr=i;
            }
        }
        return maxyr+1950;
    }
};
